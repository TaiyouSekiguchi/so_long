#include "so_long.h"


void	img_init(t_game *game)
{

	game->img[0].img = mlx_xpm_file_to_image(game->mlx, "../texture/eagle.xpm", &game->img[0].width, &game->img[0].height);
	game->img[1].img = mlx_xpm_file_to_image(game->mlx, "../texture/barrel.xpm", &game->img[1].width, &game->img[1].height);
}


int main(void)
{
	t_game	game;

	game_init(&game);
	window_init(&game);
	img_init(&game);

	mlx_put_image_to_window(game.mlx, game.win, game.img[0].img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img[0].img, 0, 64);
	mlx_put_image_to_window(game.mlx, game.win, game.img[1].img, 64, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img[1].img, 64, 64);

	mlx_loop(game.mlx);
	return (0);
}
