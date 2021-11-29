#include "so_long.h"

void	game_init(t_game *game)
{
	int	map[ROW][COL] = {
		{1, 1, 1, 1},
		{1, 0, 0, 1},
		{1, 0, 0, 1},
		{1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROW * COL);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}


void	img_init(t_game *game)
{
	game->img[0].img = mlx_xpm_file_to_image(game->mlx, "../texture/eagle.xpm", &game->img[0].width, &game->img[0].height);
	game->img[1].img = mlx_xpm_file_to_image(game->mlx, "../texture/barrel.xpm", &game->img[1].width, &game->img[1].height);
	game->img[2].img = mlx_xpm_file_to_image(game->mlx, "../texture/greystone.xpm", &game->img[2].width, &game->img[2].height);
}
