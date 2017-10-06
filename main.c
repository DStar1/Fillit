/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/05 18:38:04 by hasmith          ###   ########.fr       */
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

char *convert_to_letts(char *src, int tet_nubr_npie)
{
	char *str;
	int i;

	i = 0;
	str = src;
	//str = (char*)malloc((char_size + 1) * sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			str[i] = tet_nubr_npie + 'A'; 
		}
		i++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	char *data; //change back the makefile
	char *str;
	char **to_arr;
	int tot_char;
	int size;
	int j;
	int i;
	int tet_nubr_npie;
	int **int_arr;

	tot_char = 0;
 	if (argc > 0){
		data = argv[1];
		char *final = ft_get_stdin(argv[1], &tot_char);
		j = tot_char;
		tet_nubr_npie = check_if_valid(final, &tot_char); //try to not use this fuction here
		printf("%d\n%d\n", j, check_if_valid(final,&tot_char));

		//printf("%s\n", c);

		size = 4;
		//ft_putarr(create_new_box(&size)); 
		 to_arr = turn_into_2d(final, &tot_char);
		 int_arr = get_shape(to_arr, tet_nubr_npie);
		 //ft_putarr(to_arr);
		// for ( i = 0; to_arr[i] != '\0'; i++ )
		// {
		// 	str = to_arr[i];
		// 	printf("%s\n", convert_to_letts(str, i)); //creates 2d array of strings, only showing first string
		// 	///will print finished 2d array and will use ft_putarr()
		// }
	}
	return (0);
}
