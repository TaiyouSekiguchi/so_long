#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_game	game;

	if (argc != 2)
		my_error("Usaga: ./so_long file_name.ber");
	read_file(&list, argv[1]);
	map_create(&game.map, list);
	ft_lstclear(&list, free);
	map_check(&game, 0, 0 ,0);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, DESTROY_NOTIFY, 1L<<17, &click_cross_mark, &game);
	mlx_hook(game.win, KEY_PRESS, 1L<<0, &deal_key, &game);
	command_count_put(0);
	render_next_frame(&game);
	mlx_loop(game.mlx);
	return (0);
}