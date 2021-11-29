#include "so_long.h"

int main(void)
{
	t_game	game;
	t_img	img;

	game_init(&game);
	window_init(&game);

	img.img = mlx_xpm_file_to_image(game.mlx, "../texture/eagle.xpm", &img.width, &img.height);
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, img.img, 0, 64);

	mlx_loop(game.mlx);
	return (0);
}
