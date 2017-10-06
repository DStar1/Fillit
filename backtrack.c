/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:20:43 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/05 18:37:54 by hasmith          ###   ########.fr       */
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

int check_if_possible(t_list tet_piece_struct, char **two_d_arr, int x, int y)
{
	int **tet_piece;

	tet_peice = tet_piece_struct->content;
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

char **backtrack(char **two_d_arr, int box_size, t_list tet_peice_struct, /*int tet_cnt*/, int *tet_nbr_npie) //maybe pass size as an int pointer
{
	//int box_size;
	int tet_cnt; //tet_cnt should start at 0 for the place_piece function
	int y;
	int x;

	y = 0;
	x = 0;
	tet_count = (tet_peice_struct->content)[0][0]; //first variable in struct int array is the tet_cnt
	//box_size = 1;
	//tet_cnt = 0; declare in main
/* 	while (box_size <= tet_nubr_pie)
	{
		two_d_arr = create_new_box(box_size); //automatically starts at 4x4 if you say box_size = 1; */
		while (y < box_size + 3) //adds three to get to 4 fo rthe 4x4 array
		{
			while (x < box_size + 3)
			{
				if (check_if_possible(tet_piece_struct, two_d_arr, x, y))
				{
					//place_piece //use convert_to_letts(two_d_arr, tet_cnt)
					tet_cnt++;
					if (tet_cnt == tet_nubr_pie - 1)
						//print/store result
					else
						backtrack(two_d_arr, box_size, tet_piece_struct->next, /*tet_count++*/, tet_nbr_npie);
				}
				x++;
			}
			y++;
		}
		return (NULL); //if no solution found
//		box_size++;
//	}
}

char **solver(t_list tet_peice_struct, int *tet_nbr_npie)
{
	int box_size;
	int tet_cnt;

	box_size = 1;
	tet_cnt = 0;
	two_d_arr = create_new_box(box_size);
	while (backtrack(two_d_arr, box_size, tet_peice_struct, tet_cnt, tet_nbr_npie) == NULL)
	{
		box_size++;
		two_d_arr = create_new_box(box_size); //automatically starts at 4x4 if you say *box_size = 1;
	}
	return (backtrack(two_d_arr, box_size, tet_peice_struct, tet_cnt, tet_nbr_npie)); //returns first result that is a solution. Possibly store in a struct to find the right one
}
