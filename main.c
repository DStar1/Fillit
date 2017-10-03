/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/02 21:41:18 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	char *data;
	int i;
	int j;

	i = 0;
 	if (argc > 0){
		data = argv[1];
		char *c = ft_get_stdin(data, &i);
		j = i;
		printf("%d\n%d\n", j, check_if_valid(c,&i));
		
		printf("%s", c);
	}
	return (0);
}
