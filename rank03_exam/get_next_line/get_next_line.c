/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:03:11 by saeby             #+#    #+#             */
/*   Updated: 2023/01/05 07:46:11 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line = NULL;
	int		i;

	fd = open("text", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		printf("Line: %s", line);
		i++;
	}
	return (0);
}

/* Read from the file descriptor until we find a \n or \0
 * store the result in a temporary string
 * take a substring from start of temporary string to \n
 * store that in a line variable and return it
*/

/* Check on fd:
 * < 0
 * read (fd, 0, 0) < -1
 * BUFFER_SIZE <= 0
*/

char	*get_next_line(int fd)
{
	static char	*remaining;
	char	*buffer;
	char	*line;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remaining);
		free(buffer);
		remaining = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (0);
	line = fill_buffer(fd, buffer, remaining);
	free(buffer);
	buffer = NULL;
	remaining = set_line(line);
	return (line);
}

char	*fill_buffer(int fd, char *buffer, char *remaining)
{
	int	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(remaining);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!remaining)
			remaining = ft_strdup("");
		tmp = remaining;
		remaining = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remaining);
}

char	*set_line(char *remaining)
{
	char	*remainder;
	int		i;

	i = 0;
	while (remaining[i] != '\n' && remaining[i] != '\0')
		i++;
	if (remaining[i] == '\0' || remaining[1] == '\0')
		return (0);
	remainder = ft_substr(remaining, i + 1, ft_strlen(remaining) - i);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	remaining[i + 1] = '\0';
	return (remainder);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	int		i;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*res;

	res = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		res[j] = s2[i];
		j++;
		i++;
	}
	res[j] = 0;
	return (res);
}