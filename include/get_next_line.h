/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:21:05 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/07/20 17:21:08 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FD_SIZE 256

size_t	my_strlen(const char *s);
char	*my_strchr(const char *s, char c);
char	*my_strjoin(const char *s1, const char *s2, char c);
char	*my_strdup(const char *s, char c);
char	*get_next_line(int fd);

#endif
