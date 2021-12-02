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
	game->texs[0].img = mlx_xpm_file_to_image(game->mlx, GRASS, &game->texs[0].width, &game->texs[0].height);
	game->texs[1].img = mlx_xpm_file_to_image(game->mlx, FLOWER, &game->texs[1].width, &game->texs[1].height);
	game->texs[2].img = mlx_xpm_file_to_image(game->mlx, COLLECTIVE, &game->texs[2].width, &game->texs[2].height);
	game->texs[3].img = mlx_xpm_file_to_image(game->mlx, GOAL, &game->texs[3].width, &game->texs[3].height);
	game->texs[4].img = mlx_xpm_file_to_image(game->mlx, PLAYER, &game->texs[4].width, &game->texs[4].height);

	//game->texs[0].img = mlx_xpm_file_to_image(game->mlx, "./texture/grass.xpm", &game->texs[0].width, &game->texs[0].height);
	//game->texs[1].img = mlx_xpm_file_to_image(game->mlx, "./texture/flower.xpm", &game->texs[1].width, &game->texs[1].height);
	//game->texs[2].img = mlx_xpm_file_to_image(game->mlx, "./texture/collective.xpm", &game->texs[2].width, &game->texs[2].height);
	//game->texs[3].img = mlx_xpm_file_to_image(game->mlx, "./texture/goal.xpm", &game->texs[3].width, &game->texs[3].height);
	//game->texs[4].img = mlx_xpm_file_to_image(game->mlx, "./texture/player.xpm", &game->texs[4].width, &game->texs[4].height);
}
