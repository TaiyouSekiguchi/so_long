#include "so_long.h"

int		deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int		close(t_game *game)
{
	exit(0);
}

/*int		main_loop(t_game *game)
{
	t_img	imgs[2];

	imgs[0].img = mlx_xpm_file_to_image(game->mlx, "../texture/eagle.xpm", &imgs[0].width, &imgs[0].height);
	imgs[1].img = mlx_xpm_file_to_image(game->mlx, "../texture/greystone.xpm", &imgs[1].width, &imgs[1].height);
	mlx_put_image_to_window(game->mlx, game->win, imgs[0].img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, imgs[1].img, 0, 64);
	return (0);
}*/

int main(void)
{
	t_game	game;
	t_img	img;

	game_init(&game);
	window_init(&game);

	img.img = mlx_xpm_file_to_image(game.mlx, "../texture/eagle.xpm", &img.width, &img.height);
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 64);

	//mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	//mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close, &game);

	mlx_loop(game.mlx);
	return (0);
}
