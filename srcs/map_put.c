/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:22:55 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 15:22:56 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_put(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->row)
	{
		j = 0;
		while (j < map->col)
		{
			ft_putnbr_fd(map->map[i][j], STDOUT_FILENO);
			ft_putstr_fd(" ", STDOUT_FILENO);
			j++;
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
}
