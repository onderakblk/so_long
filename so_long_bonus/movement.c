/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:46:27 by oakbulak          #+#    #+#             */
/*   Updated: 2023/10/05 17:56:22 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	steps(t_so_long *ptr)
{
	char	*steps;
	char	*tmp;

	tmp = ft_itoa(ptr->count_step);
	steps = ft_strjoin("Steps: ", tmp);
	mlx_string_put(ptr->mlx_ptr,
		ptr->mlx_win, 10, 30, 0x00FFFFFF, steps);
	free(steps);
	free(tmp);
}

void	timer(t_so_long *s)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	s->cointimer++;
	if (s->cointimer <= 15)
		s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/coin.xpm", &a, &b);
	else if (s->cointimer <= 30)
		s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/coin1.xpm", &a, &b);
	else if (s->cointimer <= 45)
		s->coin = mlx_xpm_file_to_image(s->mlx_ptr,
				"textures/coin2.xpm", &a, &b);
	else
		s->cointimer = 0;
	if (!s->coin)
		game_end(s);
}

int	enemy_anger(t_so_long *game)
{
	timer(game);
	game->adrenaline++;
	if (game->adrenaline == 10)
		game->adrenaline = 0;
	else
		return (0);
	if (game->map[game->enemy_y][game->enemy_x - 1] == '1')
		game->wallcheck = 0;
	if (game->map[game->enemy_y][game->enemy_x + 1] == '1')
		game->wallcheck = 1;
	if (game->wallcheck && game->map[game->enemy_y][game->enemy_x - 1] != '1')
		game->enemy_x--;
	else if (!game->wallcheck
		&& game->map[game->enemy_y][game->enemy_x + 1] != '1')
		game->enemy_x++;
	return (1);
}

int	hollmovement(t_so_long *s)
{
	open_win(s, -1, -1);
	steps(s);
	if (s->player_x == s->enemy_x
		&& s->player_y == s->enemy_y)
	{
		ft_printf("Game Over!!");
		game_end(s);
	}
	if (!enemy_anger(s))
		return (0);
	if (s->map[s->enemy_y][s->enemy_x] != 'C' &&
			s->map[s->enemy_y][s->enemy_x] != 'E')
		s->map[s->enemy_y][s->enemy_x] = 'N';
	return (0);
}
