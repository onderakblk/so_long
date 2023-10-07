/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:55:15 by oakbulak          #+#    #+#             */
/*   Updated: 2023/10/05 17:26:56 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_controls4(t_so_long *s)
{
	if (s->count_p != 1 || s->count_c == 0 || s->count_e != 1)
		return (ft_printf("missing character on map\n"), free_map(s));
	if (s->map_height == s->map_width)
		return (ft_printf("Not a rectangular map!!!\n"), free_map(s));
}

void	map_control4(t_so_long *s, int x, int y)
{
	while (s->map[++y])
	{
		x = -1;
		while (s->map[y][++x])
		{
			if (s->map[y][x] == '1' || s->map[y][x] == '0'
				|| s->map[y][x] == 'C' || s->map[y][x] == 'E'
				|| s->map[y][x] == 'P')
			{
				if (s->map[y][x] == 'P')
				{
					s->player_y = y;
					s->player_x = x;
					s->count_p++;
				}
				if (s->map[y][x] == 'C')
					s->count_c++;
				if (s->map[y][x] == 'E')
					s->count_e++;
			}
			else
				return (ft_printf("wrong map!!\n"), free_map(s));
		}
	}
	map_controls4(s);
}

void	map_control3(t_so_long *s, int x, int y)
{
	if (s->map[++y])
		while (s->map[y][++x])
			if (s->map[y][x] != '1')
				return (ft_printf("Error\n"), free_map(s));
	x = -1;
	while (s->map[s->map_height - 2][++x])
		if (s->map[s->map_height - 2][x] != '1')
			return (ft_printf("Error\n"), free_map(s));
	while (y <= s->map_height - 2 && s->map[y][0])
	{
		if (s->map[y][0] != '1')
			return (ft_printf("Error\n"), free_map(s));
		y++;
	}
	y = -1;
	while (++y <= s->map_height - 2 && s->map[y][s->map_width - 2])
		if (s->map[y][s->map_width - 2] != '1')
			return (ft_printf("Error\n"), free_map(s));
	map_control4(s, -1, -1);
}

void	map_controls2(t_so_long *s, char *tmp_map)
{
	s->map = ft_split(tmp_map, '\n');
	if (!s->map)
		return (ft_printf("Not opened map"), free(tmp_map), exit(1));
	map_control3(s, -1, -1);
	map_control5(s, ft_split(tmp_map, '\n'));
	free(tmp_map);
}

void	map_control2(char *str, t_so_long *s)
{
	int		fd;
	char	*line;
	char	*tmp_map;
	char	*tmp_tmp_map;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error\nFile not opened!!!\n"), exit(1));
	line = get_next_line(fd);
	if (!line)
		return (ft_printf("Error\nEmpty Map!!!\n"), close(fd), exit(1));
	s->map_width = ft_strlen(line);
	s->map_height = 1;
	tmp_map = ft_strdup("");
	while (line)
	{
		s->map_height++;
		tmp_tmp_map = ft_strjoin(tmp_map, line);
		free(line);
		free(tmp_map);
		tmp_map = tmp_tmp_map;
		line = get_next_line(fd);
	}
	close(fd);
	map_controls2(s, tmp_map);
}
