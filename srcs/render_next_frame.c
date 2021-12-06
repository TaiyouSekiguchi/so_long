/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:23:31 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 16:43:33 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_game *game)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;
	void	*img_tmp;

	i = 0;
	while (i < game->map.row)
	{
		y = i * TILE_SIZE;
		j = 0;
		while (j < game->map.col)
		{
			x = j * TILE_SIZE;
			img_tmp = game->texs[game->map.map[i][j]].img;
			mlx_put_image_to_window(game->mlx, game->win, img_tmp, x, y);
			j++;
		}
		i++;
	}
	return (0);
}
