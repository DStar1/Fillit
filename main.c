/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/03 19:29:11 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char **create_new_box(int *size) //change all size to *size when done
{
	//size starts as 4(or 21) and is changed everytime it needs more
	int char_size;
	char **nbox;
	int i;
	int j;
	int cnt;

	i = 0;
	cnt = 0;
	char_size = *size + 4; //adjusts size variable being under 4
	nbox = (char**)malloc((char_size + 1) * sizeof(char*)); //not  sure if supposed to protect this
	while (i < char_size)
		nbox[i++] = ft_strnew(char_size);
	i = 0;
	while (i < char_size)
	{
		j = 0;
		while (j < char_size) 
			nbox[i][j++] = '.';
		nbox[i][j] = '\0';
		i++;
	}
	nbox[i] = (char*)malloc(sizeof(char)); //not  sure if supposed to protect this
	nbox[i] = NULL;
	return(nbox);
} //how to free() old 2d array(linked list?, pass back the 2d array and free()?)

int main(int argc, char **argv)
{
	char *data; //change back the makefile
	int tot_char;
	int size;
	int j;

	tot_char = 0;
 	if (argc > 0){
		data = argv[1];
		char *c = ft_get_stdin(data, &tot_char);
		j = tot_char;
		printf("%d\n%d\n", j, check_if_valid(c,&tot_char));

		printf("%s\n", c);

		size = 4;
		ft_putarr(create_new_box(&size)); 
		///will print finished 2d array and will use ft_putarr()

	}
	return (0);
}
