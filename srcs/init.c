#include "so_long.h"

void	window_init(t_game *game)
{
	int	width;
	int	height;

	width = game->map.col * TILE_SIZE;
	height = game->map.row * TILE_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
}

void	img_init(t_game *game)
{
	int	i;
	int	j;

	game->texs[0].img = mlx_xpm_file_to_image(game->mlx, "./texture/grass.xpm", &game->texs[0].width, &game->texs[0].height);
	game->texs[0].data = (int *)mlx_get_data_addr(game->texs[0].img, &game->texs[0].bpp, &game->texs[0].line_len, &game->texs[0].endian);
	game->texs[1].img = mlx_xpm_file_to_image(game->mlx, "./texture/flower.xpm", &game->texs[1].width, &game->texs[1].height);
	game->texs[1].data = (int *)mlx_get_data_addr(game->texs[1].img, &game->texs[1].bpp, &game->texs[1].line_len, &game->texs[1].endian);
	game->texs[2].img = mlx_xpm_file_to_image(game->mlx, "./texture/collective.xpm", &game->texs[2].width, &game->texs[2].height);
	game->texs[2].data = (int *)mlx_get_data_addr(game->texs[2].img, &game->texs[2].bpp, &game->texs[2].line_len, &game->texs[2].endian);
	game->texs[3].img = mlx_xpm_file_to_image(game->mlx, "./texture/goal.xpm", &game->texs[3].width, &game->texs[3].height);
	game->texs[3].data = (int *)mlx_get_data_addr(game->texs[3].img, &game->texs[3].bpp, &game->texs[3].line_len, &game->texs[3].endian);
	game->texs[4].img = mlx_xpm_file_to_image(game->mlx, "./texture/player.xpm", &game->texs[4].width, &game->texs[4].height);
	game->texs[4].data = (int *)mlx_get_data_addr(game->texs[4].img, &game->texs[4].bpp, &game->texs[4].line_len, &game->texs[4].endian);

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < TILE_SIZE * TILE_SIZE)
		{
			game->tex_color[i][j] = game->texs[i].data[j];
			j++;
		}
		i++;
	}
}
