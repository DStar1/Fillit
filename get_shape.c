/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmckee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:25:35 by kmckee            #+#    #+#             */
/*   Updated: 2017/10/05 15:17:34 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**get_shape(char **shape_str, int tet_nubr_npie)
{
	int **arr;
	int i;
	int j;
	int k;
	int l;

	/* create array of smaller arrays to hold shapes*/
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
	/* loop through all strings (i, j) putting 3 numbers (k) corresponding to shapes in the current array (i, l) */
	while(shape_str[i] != '\0')
	{
		while (shape_str[i][j] != '\0')
		{
			if (shape_str[i][j] != '#')
				j++;
			else
			{
				while (shape_str[i][j] != '#')
				{
					j++;
					k++;
				}
				arr[i][l] == k;
				l++;
				k = 1;
			}
		}
		j = 0;
		i++;
	}
	return (arr)
}
