/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:25:35 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/09 10:35:58 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	make_grid(int ***three_d_arr, int **two_d_int, int index)
{
	int x;
	int y;
	int i;
	int j;
	int k;

	x = 0;
	y = 0;
	i = 0;
	j = 0;
	k = 0;
	three_d_arr[index][i][j++] = 0;
	three_d_arr[index][i][j] = 0;
	i++;
	j = 0;
	while (k < 3)
	{
		if (two_d_int[index][k] == 5)
		{
			three_d_arr[index][i][j++] = x;
			three_d_arr[index][i++][j] = ++y;
		}
		else if (two_d_int[index][k] == 1)
		{
			three_d_arr[index][i][j++] = ++x;
			three_d_arr[index][i++][j] = y;
		}
		else if (two_d_int[index][k] == 4)
		{
			three_d_arr[index][i][j++] = --x;
			three_d_arr[index][i++][j] = ++y;
		}
		else if (two_d_int[index][k] == 3)
		{
			x = x - 2;
			three_d_arr[index][i][j++] = x;
			three_d_arr[index][i++][j] = ++y;
		}
		k++;
		j = 0;
	}
	k = 0;
}

int		**get_shape(char **two_d_arr, int tet_nubr_npie)
{
	int		**arr;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	arr = (int**)malloc(sizeof(int*) * tet_nubr_npie);
	while (i < tet_nubr_npie)
	{
		arr[i] = (int *)malloc(sizeof(int) * 3);
		i++;
	}
	i = 0;
	j = 0;
	k = 1;
	l = 0;
	while (two_d_arr[i] != 0)
	{
		while (two_d_arr[i][j] != '#')
			j++;
		while (two_d_arr[i][j] != '\0')
		{
			if (two_d_arr[i][j] == '#')
			{
				j++;
				while (two_d_arr[i][j] != '#')
				{
					j++;
					k++;
				}
				arr[i][l] = k;
				k = 1;
				l++;
			}
			if (l == 3)
				j++;
		}
		i++;
		j = 0;
		l = 0;
	}
	return (arr);
}

int		***get_three_d_arr(char **two_d_arr, int tet_nubr_npie)
{
	int	***three_d_arr;
	int **two_d_int;
	int i;
	int j;
	int tet_num;

	two_d_int = get_shape(two_d_arr, tet_nubr_npie);
	three_d_arr = (int***)malloc(sizeof(int**) * tet_nubr_npie);
	tet_num = tet_nubr_npie;
	i = 0;
	j = 0;
	while (tet_nubr_npie--)
	{
		three_d_arr[i] = (int**)malloc(sizeof(int*) * 5);
		while (j < 4)
		{
			three_d_arr[i][j] = (int*)malloc(sizeof(int) * 2);
			j++;
		}
		three_d_arr[i][4] = (int*)malloc(sizeof(int));
		three_d_arr[i][4][0] = i;
		j = 0;
		i++;
	}

	i = 0;
	while (i < tet_num)
	{
		(make_grid(three_d_arr, two_d_int, i));
		i++;

	}
	return (three_d_arr);
}
