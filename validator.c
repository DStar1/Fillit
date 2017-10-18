/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:25:28 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/18 16:54:21 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_stdin(char *buf, int *tot_char)
{
	int		ret;
	int		total_size;
	char	*final;
	char	tmp[100000];
	int		filedesc;

	filedesc = open(buf, O_RDONLY);
	total_size = 0;
	while ((ret = read(filedesc, buf, 1000)) > 0)
	{
		free(final);
		buf[ret] = '\0';
		total_size += ret;
		final = (char *)malloc(sizeof(char) * total_size);
		final = ft_strcat(tmp, buf);
	}
	*tot_char = total_size;
	return (final);
}

int		check_if_valid(char *final, int *tot_char)
{
	int numpie;
	int pos;
	int line;
	int dot;
	int pound;

	numpie = 0;
	line = 0;
	dot = 0;
	pound = 0;
	pos = 0;
	while (pos < *tot_char)
	{
		while (line <= 4 && pos < *tot_char)
		{
			if (final[pos] == '.')
				dot++;
			else if (final[pos] == '#')
				pound++;
			else if (final[pos] == '\n')
				line++;
			pos++;
		}
		if (dot != 12 || pound != 4)
			return (0);
		else
		{
			dot = 0;
			pound = 0;
			line = 0;
		}
		numpie++;
		while (final[pos] == '\n')
			pos++;
	}
	return (numpie);
}

int		check_if_valid_shape(char *shape_str)
{
	int i;
	int shared_sides;

	i = 0;
	shared_sides = 0;
	while (i < 19)
	{
		if (shape_str[i] == '#')
		{
			if (i + 1 <= 18 && shape_str[i + 1] == '#')
				shared_sides++;
			if (i - 1 >= 0 && shape_str[i - 1] == '#')
				shared_sides++;
			if (i + 5 <= 18 && shape_str[i + 5] == '#')
				shared_sides++;
			if (i - 5 >= 0 && shape_str[i - 5] == '#')
				shared_sides++;
		}
		i++;
	}
	return (shared_sides);
}

int		check_newlines(char *final)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (final[i] != '\0')
	{
		if (final[i] == '\n')
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	**turn_into_2d(char *final, int *tot_char)
{
	char	**two_d_arr;
	int		i;
	int		j;
	int		tet_nubr_npie;

	j = 0;
	i = 0;
	tet_nubr_npie = check_if_valid(final, tot_char);
	if (tet_nubr_npie == 0)
		return (0);
	two_d_arr = (char**)malloc((tet_nubr_npie + 1) * sizeof(char*));
	two_d_arr[tet_nubr_npie] = 0;
	while (j < tet_nubr_npie)
	{
		two_d_arr[j] = ft_strsub(final, i, 21);
		two_d_arr[j][20] = '\0';
		i += 21;
		j++;
	}
	j = 0;
	if ((check_newlines(final) + 1) % tet_nubr_npie != 0)
		return (0);
	while (j < tet_nubr_npie)
	{
		i = (check_if_valid_shape(two_d_arr[j]));
		if (i != 6 && i != 8)
			return (0);
		j++;
	}
	return (two_d_arr);
}
