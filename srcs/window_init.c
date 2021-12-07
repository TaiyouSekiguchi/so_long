/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:25:00 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 16:30:07 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		my_error("mlx_init failed in window_init");
}

static void	do_mlx_new_window(t_game *game, int width, int height)
{
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->win == NULL)
		my_error("mlx_new_window failed in window_init");
}

static void	decide_height(t_game *game, int max_row, int *height)
{
	if (game->map.row > max_row)
	{
		*height = (max_row - 1) * TILE_SIZE;
		game->window.row = max_row - 1;
	}
	else
	{
		*height = game->map.row * TILE_SIZE;
		game->window.row = game->map.row;
	}
}

static void	decide_width(t_game *game, int max_col, int *width)
{
	if (game->map.col > max_col)
	{
		*width = max_col * TILE_SIZE;
		game->window.col = max_col;
	}
	else
	{
		*width = game->map.col * TILE_SIZE;
		game->window.col = game->map.col;
	}
}

void	window_init(t_game *game)
{
	int	width;
	int	height;
	int	max_row;
	int	max_col;

	do_mlx_init(game);
	mlx_get_screen_size(game->mlx, &width, &height);
	max_row = height / TILE_SIZE;
	max_col = width / TILE_SIZE;
	decide_height(game, max_row, &height);
	decide_width(game, max_col, &width);
	do_mlx_new_window(game, width, height);
}
