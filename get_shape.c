/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:25:35 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/05 22:27:57 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**get_shape(char **two_d_arr, int tet_nubr_npie)
{
	int		**arr;
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	// create array of smaller arrays to hold shapes
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
	// loop through all strings (i, j) putting 3 numbers (k) corresponding to shapes in the current array (i, l)
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
