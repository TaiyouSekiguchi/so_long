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
