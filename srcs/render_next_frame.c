#include "so_long.h"

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
