#include "so_long.h"

static void	do_mlx_xpm_file_to_image(t_img *tex, void *mlx, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (tex->img == NULL)
		my_error("Error\nmlx_xpm_file_to_image is failed in img_init");
}

void	img_init(t_img *texs, void *mlx)
{
	do_mlx_xpm_file_to_image(&texs[0], mlx, GRASS);
	do_mlx_xpm_file_to_image(&texs[1], mlx, FLOWER);
	do_mlx_xpm_file_to_image(&texs[2], mlx, TREASURE);
	do_mlx_xpm_file_to_image(&texs[3], mlx, GOAL);
	do_mlx_xpm_file_to_image(&texs[4], mlx, HERO);
}
