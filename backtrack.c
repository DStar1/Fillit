/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:20:43 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/05 15:03:51 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_if_possible(t_list tet_piece, char **two_d_arr, int x, int y)
{

}

char **backtrack(int *box_size) //maybe pass size as an int pointer
{
	//int *box_size;
	char **two_d_arr;
	int tet_cnt;

	//*box_size = 1;
	tet_cnt = 0;
	while (*box_size <= tet_nubr_pie)
	{
		two_d_arr = create_new_box(*box_size); //automatically starts at 4x4 if you say *box_size = 1;
		while (y < *box_size + 3) //adds three to gwet to 4
		{
			while (x < *box_size + 3)
			{
				if (check_if_possible(tet_piece, two_d_arr, x, y))
				{
					//place_piece
					tet_cnt++;
					if (tet_cnt == tet_nubr_pie - 1)
						//print/store result
					else
						backtrack(&box_size, )
				}
				x++;
			}
			y++;
		}
		*box_size++;
	}
}
