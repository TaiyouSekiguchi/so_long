/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:20:34 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 11:35:27 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	do_mlx_xpm_file_to_image(t_img *tex, void *mlx, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (tex->img == NULL)
		my_error("mlx_xpm_file_to_image is failed in img_init");
}

void	img_init(t_img *texs, void *mlx)
{
	do_mlx_xpm_file_to_image(&texs[0], mlx, GRASS);
	do_mlx_xpm_file_to_image(&texs[1], mlx, FLOWER);
	do_mlx_xpm_file_to_image(&texs[2], mlx, TREASURE);
	do_mlx_xpm_file_to_image(&texs[3], mlx, GOAL);
	do_mlx_xpm_file_to_image(&texs[4], mlx, HERO);
	do_mlx_xpm_file_to_image(&texs[5], mlx, NORTH);
	do_mlx_xpm_file_to_image(&texs[6], mlx, EAST);
	do_mlx_xpm_file_to_image(&texs[7], mlx, WEST);
}
