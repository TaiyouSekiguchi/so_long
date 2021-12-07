/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:23:31 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 16:51:07 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_area(t_player *player, t_window *window, t_area *area)
{
	area->x = player->x / window->col;
	area->y = player->y / window->row;
}

static void	*get_img(t_game *game, int row, int col)
{
	void		*ret;
	t_img		*texs;
	t_map		*map;

	texs = game->texs;
	map = &game->map;
	if (row >= map->row || col >= map->col)
		ret = texs[WALL].img;
	else
		ret = texs[map->map[row][col]].img;
	return (ret);
}

int	render_next_frame(t_game *game, int x, int y)
{
	void		*img_tmp;
	t_area		area;
	t_matrix	matrix;
	int			i;
	int			j;

	i = 0;
	while (i < game->window.row)
	{
		y = i * TILE_SIZE;
		j = 0;
		while (j < game->window.col)
		{
			x = j * TILE_SIZE;
			get_area(&game->player, &game->window, &area);
			matrix.row = (area.y * game->window.row) + i;
			matrix.col = (area.x * game->window.col) + j;
			img_tmp = get_img(game, matrix.row, matrix.col);
			mlx_put_image_to_window(game->mlx, game->win, img_tmp, x, y);
			j++;
		}
		i++;
	}
	return (0);
}
