/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.control2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:00:14 by oakbulak          #+#    #+#             */
/*   Updated: 2023/08/24 14:00:16 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	explore_map(char **map, t_control *control, int y, int x)
{
	if (x == -1 || y == -1
		|| !map[y] || !map[y][x] || map[y][x] == '#' || map[y][x] == '1')
		return ;
	if (map[y][x] == 'E')
		control->is_the_door_accessible = 1;
	else if (map[y][x] == 'C')
		control->the_amount_of_coins_we_can_reach++;
	map[y][x] = '#';
	explore_map(map, control, y + 1, x);
	explore_map(map, control, y - 1, x);
	explore_map(map, control, y, x + 1);
	explore_map(map, control, y, x - 1);
}

void	map_control5(t_so_long *s, char	**map)
{
	t_control	control;

	control.is_the_door_accessible = 0;
	control.the_amount_of_coins_we_can_reach = 0;
	explore_map(map, &control, s->player_y, s->player_x);
	ft_malloc_error(map);
	if (!control.is_the_door_accessible)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\nI can't reach the door\n");
		exit(1);
	}
	if (control.the_amount_of_coins_we_can_reach != s->count_c)
	{
		ft_malloc_error(s->map);
		ft_printf("Error\nWhole coins cannot collect\n");
		exit(1);
	}
}
