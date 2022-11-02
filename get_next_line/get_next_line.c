/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:37:46 by saeby             #+#    #+#             */
/*   Updated: 2022/11/02 18:22:09 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *s1, char *s2);
static void	fill_str(char *res, char *s1, char *s2);
static char	*ft_strdup(char *s1);
static char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);

char	*get_next_line(int fd)
{
	static char	*s[1];
	char	buffer[BUFFER_SIZE + 1];
	int		b_read;
	char	*tmp;

	if (fd < 0)
		return (NULL);

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		buffer[b_read] = 0;
		if (!s[0])
			s[0] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s[0], buffer);
			free(s[0]);
			s[0] = tmp;
		}
		if (ft_strchr(s[0], '\n'))
			break ;
	}
	return (s[0]);
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

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
