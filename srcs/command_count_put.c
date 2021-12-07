/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_count_put.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:19:14 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 16:59:07 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	command_count_put(t_game *game)
{
	static int	command_count;

	if (command_count == INT_MAX)
		my_error("Too many move");
	ft_putstr_fd("command count: ", STDOUT_FILENO);
	ft_putnbr_fd(command_count, STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	command_count++;
}
