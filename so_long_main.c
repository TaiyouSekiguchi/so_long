#include "so_long.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	ft_putchar('X');
	return (0);
}

int	main(void)
{
	t_game	game;

	game_init(&game);
	window_init(&game);
	img_init(&game);


	mlx_key_hook(game.win, &deal_key, (void *)0);

	mlx_put_image_to_window(game.mlx, game.win, game.img[0].img, 0, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img[0].img, 0, 64);
	mlx_put_image_to_window(game.mlx, game.win, game.img[1].img, 64, 0);
	mlx_put_image_to_window(game.mlx, game.win, game.img[2].img, 64, 64);

	mlx_loop(game.mlx);
	return (0);
}
