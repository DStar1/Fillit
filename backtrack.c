/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:26:30 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/14 13:01:18 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **convert_to_letts(char **src, int tet_nubr_npie)
{
	char **str;
	int i;
	int j;

	i = 0;
	j = 0;
	str = src;
	while (str[i] != '\0')
	{
	    j = 0;
	    while(str[i][j] != '\0')
	    {
    		if (str[i][j] == '#')
    		{
    			str[i][j] = tet_nubr_npie + 'A';
    		}
    		j++;
	    }
	    i++;
	}
	return (str);
}

char **create_new_box(int size) //change all size to *size when done
{
	//size starts as 4(or 21) and is changed everytime it needs more
	int char_size;
	char **nbox;
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	char_size = size + 3; //adjusts size variable being under 4
	nbox = (char**)malloc((char_size + 1) * sizeof(char*)); //not  sure if supposed to protect this
	while (i < char_size)
		nbox[i++] = ft_strnew(char_size);
	i = 0;
	while (i < char_size)
	{
		j = 0;
		while (j < char_size)
			nbox[i][j++] = '.';
		nbox[i][j] = '\0';
		i++;
	}
	nbox[i] = (char*)malloc(sizeof(char)); //not  sure if supposed to protect this
	nbox[i] = NULL;
	return(nbox);
} //how to free() old 2d array(linked list?, pass back the 2d array and free()?)

/*
** int array is the struct the has the coordinates for the peice that looks like this
** {0, 2}
** {1, 2}
** {2, 2}
** {3, 2}
** navigate by checking the first value as x and the second value as y
*/

int check_if_possible(int **two_d_int_arr, char **two_d_arr, int x, int y)
{
	int i;
	int x1;
	int y1;
	int size;

	size = 0;
	while (two_d_arr[0][size] != '\0')
		size++;
	i = 0;
	while (i < 4)
	{
		x1 = x;
		y1 = y;
		x1 = x1 + two_d_int_arr[i][0];
		y1 = y1 + two_d_int_arr[i][1];
		if (x1 > size - 1 || y1 > size - 1 || two_d_arr[y1][x1] == '\0' || two_d_arr[y1][x1] != '.')
			return (0);
		i++;
	}
	return (1);
}


void		ft_clean_grid(char **grid, int let)
{
	int		i;
	int		j;
	char letter;

	i = 0;
	letter = let + 'A';
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == letter)
				grid[i][j] = '.';
			j++;
		}
		i++;
	}
}


//added place
char **place(int **two_d_int_arr, char **two_d_arr, int x, int y)
{
	int i;
	int x1;
	int y1;
	char **two_d_fin;

	i = 0;
	two_d_fin = two_d_arr;
	while (i < 4)
	{
		x1 = x;
		y1 = y;
		x1 = x1 + two_d_int_arr[i][0];
		y1 = y1 + two_d_int_arr[i][1];
		two_d_fin[y1][x1] = '#';
		i++;
	}
	return (two_d_fin);
}

char **backtrack(char **two_d_arr, int ***three_d, int tet_cnt, int tet_nbr_npie)
{
	int j;
	int i;
	char **tmp;
	int box_size;

//added to get rid of box size variable///
	box_size = 0;
	while (two_d_arr[box_size+3] != '\0')
		box_size++;
	//box_size = box_size - 3;
///////////

	j = -1; //reduce number of lines in code
	//tmp = NULL; //possible to change whole function to int and change **char within (less variables)
	if (tet_cnt == tet_nbr_npie)
		return (two_d_arr); //finishes the code
	while (j++ < box_size + 3) //adds three to get to 4 fo rthe 4x4 array
	{
		i = -1;
		while (i++ < box_size + 3)
		{
			if ((check_if_possible(three_d[tet_cnt], two_d_arr, i, j)))
			{
				//two_d_arr = place(three_d[tet_cnt], two_d_arr, i, j);
				two_d_arr = convert_to_letts(place(three_d[tet_cnt], two_d_arr, i, j), tet_cnt);
				if ((tmp = backtrack(two_d_arr, three_d, tet_cnt+1, tet_nbr_npie)))
					return (tmp);
				ft_clean_grid(two_d_arr, tet_cnt);
			}
			//i++;
		}
		//j++;
	}
	return (0); //if no solution found
}

//free 2d array
void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != '\0')
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}

int		round_up_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

char **solver(int ***three_d_int_arr, int tet_nbr_npie)
{
	int box_size;
	int tet_cnt;
	char **two_d_arr;

	box_size = 0;
	tet_cnt = 0;
	box_size = round_up_sqrt(tet_nbr_npie * 4) - 3; //when box_size = 1, it is 4x4
	two_d_arr = NULL;
	while (!two_d_arr)
	{
		//	printf("Box_size: %d\n", box_size);
		//free_array(two_d_arr); //causes seg fault?
		two_d_arr = create_new_box(box_size); //automatically starts at 4x4 if you say *box_size = 1;
		two_d_arr = backtrack(two_d_arr, three_d_int_arr, tet_cnt, tet_nbr_npie);
		box_size++;
	}
	ft_putarr(two_d_arr);
	return (two_d_arr);
}
