/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:25:28 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/03 20:10:11 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_stdin(char *buf, int *tot_char) //pass the adress of i to other functions so it can be manipulated and used
{
	int		ret;
	int		total_size;
	char	*final;
	char	tmp[100000];
	int		filedesc;

	filedesc = open("test.txt", O_RDONLY);
	total_size = 0;
	//final = malloc(0);
	while ((ret = read(filedesc, buf, 1000)) > 0)
	{
		//ft_strcpy(tmp, final);
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

// char	**turn_into_2d(char *final)
// {
// 	char 2d_arr;

// 	while(final[i] != '\n')

// }
