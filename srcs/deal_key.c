/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:19:21 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 16:30:10 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.map[i][j] == PLAYER)
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	map_save(int *map, int *save, int *c_cnt, int *clear)
{
	if (*map != EXIT)
	{
		*save = EMPTY;
		if (*map == COLLECTIBLE)
		{
			*c_cnt -= 1;
		}
	}
	else
	{
		*save = EXIT;
		if (*c_cnt == 0)
			*clear = 1;
	}
}

static void	map_modify(t_game *game, int dx, int dy)
{
	static int	save;
	static int	clear;
	int			next_x;
	int			next_y;

	next_x = game->player.x + dx;
	next_y = game->player.y + dy;
	if (clear == 1)
		return ;
	if (game->map.map[next_y][next_x] != WALL)
	{
		game->map.map[game->player.y][game->player.x] = save;
		map_save(&game->map.map[next_y][next_x], &save, &game->c_cnt, &clear);
		game->map.map[next_y][next_x] = PLAYER;
		command_count_put();
	}
	clear_check(clear, &game->map.map[next_y][next_x]);
}

int	deal_key(int key, t_game *game)
{
	get_player(game);
	if (key == KEY_ESC)
		game_exit(game);
	else if (key == KEY_W)
		map_modify(game, 0, -1);
	else if (key == KEY_S)
		map_modify(game, 0, 1);
	else if (key == KEY_A)
		map_modify(game, -1, 0);
	else if (key == KEY_D)
		map_modify(game, 1, 0);
	render_next_frame(game);
}
