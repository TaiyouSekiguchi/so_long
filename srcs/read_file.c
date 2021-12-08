/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:23:05 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/08 23:10:52 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"

void	read_file(t_list **list, char *file_path)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		my_perror();
	*list = NULL;
	ret = get_next_line(fd, &line);
	if (ret == ERROR)
		my_error("gnl error");
	while (ret > 0)
	{
		ft_lstadd_back(list, ft_lstnew(line));
		ret = get_next_line(fd, &line);
		if (ret == ERROR)
			my_error("gnl error");
	}
	free(line);
	close(fd);
}
