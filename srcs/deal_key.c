#include "so_long.h"

void	get_player(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.row)
	{
		j = 0;
		while (j < game->map.col)
		{
			if (game->map.map[i][j] == 4)
			{
				game->player.x = j;
				game->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	map_modify(t_game *game, int dx, int dy)
{
	if (game->map.map[game->player.y + dy][game->player.x + dx] != 1)
	{
		game->map.map[game->player.y][game->player.x] = 0;
		game->map.map[game->player.y + dy][game->player.x + dx] = 4;
	}
}



int	deal_key(int key, t_game *game)
{
	get_player(game);
	if (key == KEY_ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (key == KEY_W)
		map_modify(game, 0, -1);
	else if (key == KEY_S)
		map_modify(game, 0, 1);
	else if (key == KEY_A)
		map_modify(game, -1, 0);
	else if (key == KEY_D)
		map_modify(game, 1, 0);
	render_next_frame(game);
}
