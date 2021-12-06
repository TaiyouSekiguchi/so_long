/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:19:44 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/06 15:19:46 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	extension_check(char *file_path)
{
	size_t	path_len;

	path_len = ft_strlen(file_path);
	if (path_len <= 4)
		return (0);
	if ((file_path[path_len - 4] == '.')
		&& (file_path[path_len - 3] == 'b')
		&& (file_path[path_len - 2] == 'e')
		&& (file_path[path_len - 1] == 'r'))
		return (1);
	return (0);
}
