/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:25:00 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 15:25:02 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_mlx_init(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		my_error("Error\nmlx_init failed in window_init");
}

static void	do_mlx_new_window(t_game *game, int width, int height)
{
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->win == NULL)
		my_error("Error\nmlx_new_window failed in window_init");
}

void	window_init(t_game *game)
{
	int	width;
	int	height;

	if ((INT_MAX / TILE_SIZE < game->map.col)
		|| (INT_MAX / TILE_SIZE < game->map.row))
		my_error("Error\nsize over in window_init");
	width = game->map.col * TILE_SIZE;
	height = game->map.row * TILE_SIZE;
	do_mlx_init(game);
	do_mlx_new_window(game, width, height);
}
