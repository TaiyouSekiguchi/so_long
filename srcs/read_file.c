/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:23:05 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/07 16:06:56 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_file(t_list **list, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		my_perror();
	*list = NULL;
	line = get_next_line(fd);
	if (line == NULL)
		my_error("Empty file or gnl error");
	while (line != NULL)
	{
		ft_lstadd_back(list, ft_lstnew(line));
		line = get_next_line(fd);
	}
	close(fd);
}
