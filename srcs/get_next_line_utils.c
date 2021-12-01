/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 17:21:40 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/07/20 17:21:42 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*my_strchr(const char *s, char c)
{
	size_t	count;
	size_t	i;

	if (s == NULL)
		return (NULL);
	count = my_strlen(s);
	i = 0;
	while (i <= count)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

static char	*my_malloc(char **ret, int len, const char *s1)
{
	*ret = (char *)malloc(sizeof(char) * len);
	if (*ret == NULL)
	{
		free((char *)s1);
		return (NULL);
	}
	return (*ret);
}

char	*my_strjoin(const char *s1, const char *s2, char c)
{
	char	*ret;
	char	*tmp1;
	char	*tmp2;
	int		len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = my_strlen(s1) + my_strchr(s2, c) - s2 + 1;
	if (c != '\0')
		len++;
	ret = my_malloc(&ret, len, s1);
	if (ret == NULL)
		return (NULL);
	tmp1 = ret;
	tmp2 = (char *)s1;
	while (*tmp2 != '\0')
		*tmp1++ = *tmp2++;
	while (*s2 != '\0' && *s2 != c)
		*tmp1++ = *s2++;
	if (c != '\0')
		*tmp1++ = c;
	*tmp1 = '\0';
	free((char *)s1);
	return (ret);
}

char	*my_strdup(const char *s, char c)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (s == NULL || my_strchr(s, c) == NULL)
		return (NULL);
	len = my_strchr(s, c) - s + 1;
	if (c != '\0')
		len++;
	ret = (char *)malloc(sizeof(char) * len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (s[i] != c)
	{
		ret[i] = s[i];
		i++;
	}
	if (c != '\0')
	{
		ret[i] = c;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
