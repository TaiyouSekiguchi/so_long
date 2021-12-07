/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:21:05 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 14:11:45 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	first_or_last_row_check(int *map, int col)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (map[i] != 1)
			my_error("Map is not closed");
		i++;
	}
}

static void	first_or_last_col_check(int *map, int col)
{
	if (map[0] != 1 || map[col - 1] != 1)
		my_error("Map is not closed");
}

static void	count_check(int c_cnt, int e_cnt, int p_cnt)
{
	if (c_cnt < 1)
		my_error("No collectible in map");
	if (e_cnt < 1)
		my_error("NO exit in map");
	if (p_cnt != 1)
		my_error("Player is incorrect in map");
}

static void	map_count(int map, int *c_cnt, int *e_cnt, int *p_cnt)
{
	if (map == COLLECTIBLE)
		*c_cnt += 1;
	else if (map == EXIT)
		*e_cnt += 1;
	else if (map == DOWN)
		*p_cnt += 1;
}

void	map_check(t_game *game, int c_cnt, int e_cnt, int p_cnt)
{
	int	i;
	int	j;

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
				map_count(game->map.map[i][j], &c_cnt, &e_cnt, &p_cnt);
				j++;
			}
		}
		i++;
	}
	count_check(c_cnt, e_cnt, p_cnt);
	game->c_cnt = c_cnt;
}
