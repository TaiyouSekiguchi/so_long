/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_next_frame.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:23:31 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 15:24:54 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_next_frame(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->texs[game->map.map[i][j]].img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}

	return (0);
}
