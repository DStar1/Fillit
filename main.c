/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 20:33:16 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/18 17:33:48 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int		tot_char;
	int		tet_nbr_npie;
	int		***int_arr;
	char	*final;

	tot_char = 0;
	if (argc > 0)
	{
		final = ft_get_stdin(argv[1], &tot_char);
		if (!final)
		{
			ft_putstr("error\n");
			return (0);
		}
		tet_nbr_npie = check_if_valid(final, &tot_char);
		if (turn_into_2d(final, &tot_char) == 0)
		{
			ft_putstr("error\n");
			return (0);
		}
		int_arr = get_three_d_arr(turn_into_2d(final, &tot_char), tet_nbr_npie);
		solver(int_arr, tet_nbr_npie);
	}
	return (0);
}
