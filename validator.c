/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 20:25:28 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/02 21:42:51 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_get_stdin(char *buf, int *i) //pass the adress of i to other functions so it can be manipulated and used
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
	*i = total_size;
	return (final);
}

int		check_if_valid(char *final, int *i)
{
	// i = nbr of chars in test.txt
	int j;
	j = *i;
	int checked = 0;
	while (j >= 0)
	{
		if (final[j] == '#')
		{
			checked++;
		}
		j--;
	}
	return (checked);
}

// char	**turn_into_2d(char *final)
// {
// 	char 2d_arr;

// 	while(final[i] != '\n')

// }
