#include "so_long.h"

static void	first_or_last_row_check(int *map, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (map[i] != 1)
			my_error("map is not closed");
		i++;
	}
}

static void	first_or_last_col_check(int *map, int col)
{
	if (map[0] != 1 || map[col - 1] != 1)
		my_error("map is not closed");
}

static void	count_check(int	c_cnt, int e_cnt, int p_cnt)
{
	if (c_cnt < 1)
		my_error("Error\nno collective");
	if (e_cnt != 1)
		my_error("Error\nexit is not correct");
	if (p_cnt != 1)
		my_error("Error\nplayer is not correct");
}

void	map_check(t_game *game)
{
	int	c_cnt;
	int	e_cnt;
	int	p_cnt;
	int	i;
	int	j;

	c_cnt = 0;
	e_cnt = 0;
	p_cnt = 0;
	i = 0;
	while (i < game->map.row)
	{
		if (i == 0 || i == game->map.row - 1)
			first_or_last_row_check(game->map.map[i], game->map.col);
		else
		{
			first_or_last_col_check(game->map.map[i], game->map.col);
			j = 0;
			while (j < game->map.col)
			{
				if (game->map.map[i][j] == 2)
					c_cnt++;
				else if (game->map.map[i][j] == 3)
					e_cnt++;
				else if (game->map.map[i][j] == 4)
					p_cnt++;
				j++;
			}
		}
		i++;
	}
	count_check(c_cnt, e_cnt, p_cnt);
	game->c_cnt = c_cnt;
}
