/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/02 19:25:31 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"



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
	*i = ret;
	return (final);
}

// int		check_if_valid(char *final)
// {

// }

// char	**turn_into_2d(char *final)
// {
// 	char 2d_arr;

// 	while(final[i] != '\n')

// }

int main(int argc, char **argv)
{
	char *data;
	int *i;
	size_t j;

 	if (argc > 0){
		data = argv[1];
		j = i;
		ft_get_stdin(data, j);
		printf("%d\n", j);
		
		//printf("%s", ft_get_stdin(data));
	}
	return (0);
}
