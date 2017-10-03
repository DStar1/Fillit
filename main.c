/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/02 18:08:22 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"

int main(void)
{
	char data[1];
	int filedesc = open("testfile.txt", O_RDONLY);
	printf("%d, %zu", (filedesc), read(filedesc,data, 1));
	//char *str = (read(filedesc,data, 128))
	return (0);
}
