/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:37:46 by saeby             #+#    #+#             */
/*   Updated: 2022/11/04 17:54:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *s1, char *s2);
static void	fill_str(char *res, char *s1, char *s2);
static char	*ft_strdup(char *s1);
static char	*ft_strchr(char *s, int c);
static int _len_till_backslash(char * s);
static size_t	ft_strlen(char *s);

char	*get_next_line(int fd)
{
	static char	*s;
	char	buffer[BUFFER_SIZE + 1];
	int		b_read;
	char	*tmp;
	int		i;
	int		original_len;
	if (s)
	{
		i = ft_strlen(s);
		original_len = _len_till_backslash(s);
	}
	else
	{
		i = 0;
		original_len = 0;
	}
	if (fd < 0)
		return (NULL);
	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = 0;
		if (!s)
			s = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s, buffer);
			free(s);
			s = tmp;
		}
		if (ft_strchr(s, '\n'))
			break ;
	}
	while (s[i] != '\n' && s[i] != 0)
		i++;
	s[i] = '\n';
	s[i++] = 0;
	return (s + original_len);
}

static char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static int _len_till_backslash(char * s)
{
	int	i;

	i = 0;
	while (s[i] != '\n' && s[i] != 0)
		i++;
	return (i);
}

static char	*ft_strjoin(char *s1, char *s2)
{
	char			*res;

	res = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	fill_str(res, s1, s2);
	return (res);
}

static void	fill_str(char *res, char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

static size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
