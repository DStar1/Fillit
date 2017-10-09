/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 21:36:23 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/08 18:31:02 by hasmith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

//#define BUF_SIZE 32

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

// typedef struct		s_list
// {
// 	void			*content;
// 	size_t			content_size;
// 	struct s_list	*next;
// }					t_list;

char	*ft_get_stdin(char *buf, int *i);
int		check_if_valid(char *final, int *tot_char);
char	**turn_into_2d(char *final, int *tot_char);
int		**get_shape(char **two_d_arr, int tet_nubr_npie);
int     check_if_possible(int **two_d_int_arr, char **two_d_arr, int x, int y);
char    **backtrack(char **two_d_arr, int box_size, int ***tree_d_int_arr, int tet_cnt, int tet_nbr_npie);
char    **solver(int ***tree_d_int_arr, int tet_nbr_npie);
char    **create_new_box(int size);


#endif
