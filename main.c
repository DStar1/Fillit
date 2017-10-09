/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/09 10:24:56 by kmckee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	int k;
	int tet_nubr_npie;
	int ***int_arr;

	tot_char = 0;
 	if (argc > 0){
		data = argv[1];
		char *final = ft_get_stdin(argv[1], &tot_char);
		j = tot_char;
		tet_nubr_npie = check_if_valid(final, &tot_char); //try to not use this fuction here
		//	printf("%d\n%d\n", j, check_if_valid(final,&tot_char));

		//printf("%s\n", c);

		size = 4;
		//ft_putarr(create_new_box(&size));
		 to_arr = turn_into_2d(final, &tot_char);
		 int_arr = get_three_d_arr(to_arr, tet_nubr_npie);
		 int count = 0;
		 i = 0;
		 while (count < tet_nubr_npie)
		 {
			 printf("Shape number: %i\n", int_arr[count][4][0]);
			 while (i < 4)
			 {
				 printf("Coordinate set %i: [%i,%i]\n", i, int_arr[count][i][0], int_arr[count][i][1]);
				 i++;
			 }
			 ft_putchar('\n');
			 count++;
			 i = 0;
		 }
		// int three_d_int_arr[2][4][2] = {
		// 	{{0,0}, {1, 0}, {2, 0}, {2, 1}},
		// 	{{0,0}, {1, 0}, {2, 0}, {3, 0}},
		// };
		// solver(three_d_int_arr, tet_nubr_npie);
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
