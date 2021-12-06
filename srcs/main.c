#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_list	*list;
	t_game	game;

	if (argc != 2)
		my_error("Usaga: ./so_long file_name.ber");
	if (!extension_check(argv[1]))
		my_error("File extension is not (*****.ber)");

	read_file(&list, argv[1]);
	map_create(&game.map, list);
	ft_lstclear(&list, free);
	map_check(&game, 0, 0 ,0);

	window_init(&game);
	img_init(game.texs, game.mlx);

	mlx_hook(game.win, DESTROY_NOTIFY, 1L<<17, &game_exit, &game);
	mlx_hook(game.win, KEY_PRESS, 1L<<0, &deal_key, &game);
	mlx_hook(game.win, MAP_NOTIFY, 1L<<0, &render_next_frame, &game);
	command_count_put(0);
	render_next_frame(&game);
	mlx_loop(game.mlx);
	return (0);
}
