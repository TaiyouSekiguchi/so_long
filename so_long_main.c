#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, t_game *game)
{
	if (key == 0xff1b)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
}

int	my_close(int key, t_game *game)
{
	exit(0);
	return (0);
}

int	render_next_frame(t_game *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < ROW)
	{
		j = 0;
		while (j < COL)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->imgs[game->map[i][j]].img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	window_init(&game);
	img_init(&game);

	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 1L<<17, &my_close, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L<<0, &deal_key, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
