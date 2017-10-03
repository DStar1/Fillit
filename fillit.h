/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 21:36:23 by hasmith           #+#    #+#             */
/*   Updated: 2017/10/02 21:38:56 by hasmith          ###   ########.fr       */
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
int		check_if_valid(char *final, int *i);

#endif
