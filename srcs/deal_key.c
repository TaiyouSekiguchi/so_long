#include "so_long.h"

int	deal_key(int key, t_game *game)
{
	if (key == 0xff1b)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
}
