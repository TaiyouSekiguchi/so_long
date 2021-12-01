/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:16:06 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/07/20 17:17:51 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_check(char **line, char **save)
{
	char	*tmp;

	if (line == NULL || save == NULL)
		return (NULL);
	*line = my_strdup(*save, '\n');
	tmp = my_strdup(my_strchr(*save, '\n') + 1, '\0');
	if (*line == NULL || tmp == NULL)
		return (NULL);
	free(*save);
	*save = tmp;
	return (*line);
}

static char	*empty_string(char *s)
{
	char	*ret;

	if (s != NULL)
		return (s);
	else
	{
		ret = (char *)malloc(sizeof(char));
		if (ret == NULL)
			return (NULL);
		*ret = '\0';
	}
	return (ret);
}

static int	my_buffering(int fd, char **line, char **save)
{
	char	*buf;
	int		ret;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	ret = read(fd, buf, BUFFER_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (my_strchr(buf, '\n') == NULL)
			*save = my_strjoin(*save, buf, '\0');
		else
		{
			*line = my_strjoin(*save, buf, '\n');
			*save = my_strdup(my_strchr(buf, '\n') + 1, '\0');
			break ;
		}
		ret = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (ret > 0 && (*line == NULL || *save == NULL))
		ret = -2;
	return (ret);
}

static void	my_free(char *line, char *save)
{
	if (line != NULL)
	{
		free(line);
		line = NULL;
	}
	if (save != NULL)
	{
		free(save);
		save = NULL;
	}
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*save[FD_SIZE];
	int				ret;

	if (fd <= -1 || fd >= FD_SIZE || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (my_strchr(save[fd], '\n') != NULL)
		return (save_check(&line, &save[fd]));
	save[fd] = empty_string(save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	ret = my_buffering(fd, &line, &save[fd]);
	if (ret == 0)
	{
		if (my_strlen(save[fd]) != 0)
			line = my_strdup(save[fd], '\0');
		free(save[fd]);
		save[fd] = NULL;
	}
	if (ret < 0)
		my_free(line, save[fd]);
	return (line);
}
