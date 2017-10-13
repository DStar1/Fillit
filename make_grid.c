/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 20:01:44 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/12 22:32:27 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	grid_helper(int ***three_d_arr, int **two_d, int ind, int i)
{
	int x;
	int y;
	int j;
	int k;

	x = 0;
	y = 0;
	k = -1;
	while (k++ < 3)
	{
		j = 0;
		if (two_d[ind][k] == 3)
			x -= 2;
		if (two_d[ind][k] == 4)
			x--;
		if (two_d[ind][k] == 1)
			x++;
		three_d_arr[ind][i][j++] = x;
		if (two_d[ind][k] == 5 || two_d[ind][k] == 3 || two_d[ind][k] == 4)
			three_d_arr[ind][i++][j] = ++y;
		else
			three_d_arr[ind][i++][j] = y;
	}
}

void	make_grid(int ***three_d_arr, int **two_d, int index)
{
	int i;
	int j;

	i = 0;
	j = 0;
	three_d_arr[index][i][j++] = 0;
	three_d_arr[index][i][j] = 0;
	i++;
	grid_helper(three_d_arr, two_d, index, i);
}
