/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:52:40 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/05 15:27:28 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft/libft.h"

/*
** Find out how many tetrominos they give us and store it in tet_num
** Find tetromino coordinates and stor them in structs nodes in a linked list named tetrominos
** Start recursion backtracking by itterating to the last x coordinate and then once the end is reached,
** itterate the y coordinate the itterate through all the tetrominos, backtrack to make them fit until there are none left.
** seve this result in a struct and repeat and return the first one that has the least dimensions
**
** functions: 
** read_buff(store in 2d_array)\, 
** validator(filler == '.', char == '#', 4x4 (tet_counter()\, save_if_all_valid())), 
** find_shape(convert_to_letts),
** create_new_box(1more dimension)\, free_old_box() 
** solver(backtracker(iterator()), store_results(all_in_one_array_saparated_by'\n\n'), ), 
** print_result()\
*/

//char	**ft_backtrack(int tet_num, t_list **tettronimos, )
int main(int argc, char **argv)
{
	/*
	** start dimensions are 4x4
	*/
	int *tot_char; //setting tot_char in ft_get_stdin()
	char *final;
	char **to_arr;
	int **int_arr;

	tot_char = 0;
	if (argc > 0)
	{
		final = ft_get_stdin(argv[1], &tot_char); //gettting tot_char and reading file
		to_arr = turn_into_2d(final, &tot_char);
		int_arr = get_shape(to_arr, tet_nubr_npie);
	}
	return (0);
}

