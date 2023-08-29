/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:00:44 by oakbulak          #+#    #+#             */
/*   Updated: 2023/08/24 15:00:45 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_end(t_so_long *s)
{
	ft_malloc_error(s->map);
	mlx_destroy_image(s->mlx_ptr, s->background);
	mlx_destroy_image(s->mlx_ptr, s->coin);
	mlx_destroy_image(s->mlx_ptr, s->door);
	mlx_destroy_image(s->mlx_ptr, s->playerimg);
	mlx_destroy_window(s->mlx_ptr, s->mlx_win);
	exit(0);
}

void	free_map(t_so_long *s)
{
	ft_malloc_error(s->map);
	exit(0);
}
