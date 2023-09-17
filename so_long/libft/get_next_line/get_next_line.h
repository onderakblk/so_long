/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:42:57 by oakbulak          #+#    #+#             */
/*   Updated: 2023/08/08 11:00:03 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

char	*ft_sj(char const *s1, char const *s2);
void	*ft_free_stash(char **stash, int create_line);
char	*get_next_line(int fd);
int		ft_have_nl(char *s);

#endif
