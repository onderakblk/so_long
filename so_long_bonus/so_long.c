/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:28:34 by oakbulak          #+#    #+#             */
/*   Updated: 2023/08/21 16:28:37 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_control(char *str, t_so_long *s)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 1] == 'r' && str[len -2] == 'e'
		&& str[len - 3] == 'b' && str[len - 4] == '.')
		map_control2(str, s);
	else
	{
		ft_printf("Wrong map name");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_so_long	s;

	s.count_c = 0;
	s.count_e = 0;
	s.count_p = 0;
	s.count_n = 0;
	s.count_step = 0;
	if (argc == 2)
	{
		map_control(argv[1], &s);
		map_shows1(&s);
	}
	else
		ft_printf("Wrong Arguments!!");
	return (0);
}
