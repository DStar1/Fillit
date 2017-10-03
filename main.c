/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/03 15:58:01 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int argc, char **argv)
{
	char *data;
	int tot_char;
	int j;

	tot_char = 0;
 	if (argc > 0){
		data = argv[1];
		char *c = ft_get_stdin(data, &tot_char);
		j = tot_char;
		printf("%d\n%d\n", j, check_if_valid(c,&tot_char));

		printf("%s", c);
	}
	return (0);
}
