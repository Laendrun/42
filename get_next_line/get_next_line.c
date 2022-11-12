/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:27:11 by saeby             #+#    #+#             */
/*   Updated: 2022/11/12 16:53:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*_get_line(int fd, char *left_c, char *line);

static char	*ft_strjoin(char *s1, char *s2);
static void	fill_str(char *res, char *s1, char *s2);
static char	*ft_strdup(char *s1);
static char	*ft_strchr(char *s, int c);
static size_t	ft_strlen(char *s);

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	line = NULL;
	line = ft_strdup(_get_line(fd, left_c, line));

	return (line);
}

static char	*_get_line(int fd, char *left_c, char *line)
{

	return (line);
}
