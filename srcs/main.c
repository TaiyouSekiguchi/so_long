#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Usaga: ./so_long file_name.bar", STDOUT_FILENO);
		return (0);
	}


	game_init(&game);
	window_init(&game);
	img_init(&game);

	mlx_hook(game.win, X_EVENT_DESTROY_NOTIFY, 1L<<17, &click_cross_mark, &game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 1L<<0, &deal_key, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
