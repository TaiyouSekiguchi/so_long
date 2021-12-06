/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:19:31 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 15:19:37 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_error(char *msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(1);
}

void	printf_error(void)
{
	printf("Error\n%m\n");
	exit(1);
}
