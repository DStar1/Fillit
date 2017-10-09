/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack_int_arr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:26:30 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/08 17:54:46 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	int **tet_piece; //possibly get rid of and use two_d_int_arr
	int i;

	i = 0;
	tet_piece = two_d_int_arr;
	while (i < 4)
	{
		x = tet_piece[i][0];
		y = tet_piece[i][1];
		if (two_d_arr[x][y] != '.')
			return (0);
		i++;
	}
	return (1);
}

char **backtrack(char **two_d_arr, int box_size, int ***three_d_int_arr, int tet_cnt, int *tet_nbr_npie) //maybe pass size as an int pointer
{
	//int box_size;
	//int tet_cnt; //tet_cnt should start at 0 for the place_piece function
	int y;
	int x;
    int int_arr;
    int **two_d_int_arr;

	y = 0;
	x = 0;
    int_arr = 0;
    two_d_int_arr = three_d_int_arr[tet_cnt];
	//tet_count = three_d_int_arr[4][0]; //last variable in struct int array is the tet_cnt
	//box_size = 1;
	//tet_cnt = 0; declare in main
/* 	while (box_size <= tet_nubr_pie)
	{
		two_d_arr = create_new_box(box_size); //automatically starts at 4x4 if you say box_size = 1; */
		while (y < box_size + 3) //adds three to get to 4 fo rthe 4x4 array
		{
			while (x < box_size + 3)
			{
				if (check_if_possible(two_d_int_arr, two_d_arr, x, y))
				{
					//place_piece //use convert_to_letts(two_d_arr, tet_cnt)
					tet_cnt++;
					if (tet_cnt == *tet_nbr_npie - 1)
						printf("yes");
						//print/store result
					else
						backtrack(two_d_arr, box_size, three_d_int_arr, tet_cnt++, tet_nbr_npie);
				}
				x++;
			}
			y++;
		}
		return (NULL); //if no solution found
//		box_size++;
//	}
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
	char_size = size + 4; //adjusts size variable being under 4
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

char **solver(int ***three_d_int_arr, int *tet_nbr_npie)
{
	int box_size;
	int tet_cnt;
	char **two_d_arr;

	box_size = 1;
	tet_cnt = 0;
	two_d_arr = create_new_box(box_size);
	while (backtrack(two_d_arr, box_size, three_d_int_arr, tet_cnt, tet_nbr_npie) == NULL)
	{
        tet_cnt = 0; //sets tet_cnt back to the start
		box_size++; //increases box size
		two_d_arr = create_new_box(box_size); //automatically starts at 4x4 if you say *box_size = 1;
	}
	return (backtrack(two_d_arr, box_size, three_d_int_arr, tet_cnt, tet_nbr_npie)); //returns first result that is a solution. Possibly store in a struct to find the right one
}