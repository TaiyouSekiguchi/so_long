#include "so_long.h"

/*void	game_init(t_game *game)
{
	int	map[ROW][COL] = {
		{1, 1, 1, 1, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 0, 0, 0, 1},
		{1, 1, 1, 1, 1},
	};
	memcpy(game->map, map, sizeof(int) * ROW * COL);
}*/

void	window_init(t_game *game)
{
	int	width;
	int	height;

	width = game->map.col * TILE_SIZE;
	height = game->map.row * TILE_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, width, height, "mlx 42");
}

void	img_init(t_game *game)
{
	game->imgs[0].img = mlx_xpm_file_to_image(game->mlx, "../texture/eagle.xpm", &game->imgs[0].width, &game->imgs[0].height);
	game->imgs[1].img = mlx_xpm_file_to_image(game->mlx, "../texture/greystone.xpm", &game->imgs[1].width, &game->imgs[1].height);
	game->imgs[2].img = mlx_xpm_file_to_image(game->mlx, "../texture/barrel.xpm", &game->imgs[2].width, &game->imgs[2].height);
}
