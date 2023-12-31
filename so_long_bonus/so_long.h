/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:38:58 by oakbulak          #+#    #+#             */
/*   Updated: 2023/10/05 17:58:07 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <fcntl.h>

# define W		13
# define S		1
# define A		0
# define D		2
# define ESC	53
# define P		64

typedef struct s_so_long
{
	char	**map;
	int		map_width;
	int		map_height;
	int		count_p;
	int		count_c;
	int		count_e;
	int		count_step;
	int		count_n;
	int		enemy_x;
	int		enemy_y;
	int		adrenaline;
	int		wallcheck;
	int		cointimer;
	int		player_x;
	int		player_y;
	void	*mlx_win;
	void	*mlx_ptr;
	void	*playerimg;
	void	*enemyimg;
	void	*wall;
	void	*background;
	void	*coin;
	void	*door;
}	t_so_long;

typedef struct s_control
{
	int	is_the_door_accessible;
	int	the_amount_of_coins_we_can_reach;
}	t_control;

void	map_control5(t_so_long *s, char	**map);
void	map_control4(t_so_long *s, int x, int y);
void	map_control3(t_so_long *s, int x, int y);
void	map_controls2(t_so_long *s, char *tmp_map);
void	map_control2(char *str, t_so_long *s);
void	map_control(char *str, t_so_long *s);
void	player_movement(t_so_long *s, int x, int y);
void	check_door(t_so_long *s, int a, int b);
void	charackter_show(t_so_long *s, char c);
void	game_over(int a, t_so_long *s);
int		movement(int key, t_so_long *s);
void	open_win(t_so_long *s, int x, int y);
void	map_shows1(t_so_long *s);
void	map_control4(t_so_long *s, int x, int y);
void	game_end(t_so_long *s);
void	free_map(t_so_long *s);
int		hollmovement(t_so_long *s);

#endif
