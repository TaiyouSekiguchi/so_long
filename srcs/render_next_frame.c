/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:23:31 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 10:06:16 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_area(t_player *player, t_window *window, int *area_x, int *area_y)
{
	*area_x = player->x / window->col;
	*area_y = player->y / window->row;
}

static void	*get_img(t_game *game, int row, int col)
{
	void		*ret;
	t_img		*texs;
	t_map		*map;
	t_window	*window;

	texs = game->texs;
	map = &game->map;
	window = &game->window;

	if (row >= map->row
		|| col >= map->col)
		ret = texs[WALL].img;
	else
		ret = texs[map->map[row][col]].img;
	return (ret);
}

int	render_next_frame(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;
	void	*img_tmp;
	int		area_x;
	int		area_y;

	get_area(&game->player, &game->window, &area_x, &area_y);
	i = 0;
	while (i < game->window.row)
	{
		y = i * TILE_SIZE;
		j = 0;
		while (j < game->window.col)
		{
			x = j * TILE_SIZE;
			img_tmp = get_img(game, (area_y * game->window.row) + i, (area_x * game->window.col) + j);
			mlx_put_image_to_window(game->mlx, game->win, img_tmp, x, y);
			j++;
		}
		i++;
	}
	return (0);
}
