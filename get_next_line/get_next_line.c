/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:27:11 by saeby             #+#    #+#             */
/*   Updated: 2022/11/30 09:04:55 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * ssize_t type => signed size_t
 * can be -1 which is the result of an error for
 * most system calls
 */

#include "get_next_line.h"

static char		*_fill_line_buffer(int fd, char *left_c, char *buffer);
static char		*_set_line(char *line);
static char		*ft_strchr(char *s, int c);

/*
 * the main function get_next_line "only" makes some check
 * about the file descriptor and the different memory allocations
 * once all the checks are done, it calls the _filL_line_buffer function
 * to read in the file descriptor until it finds a \n or \0 character
 * once the line variable is filled, we free the buffer so we don't have
 * any memory leaks, since it's not used after that.
 * once the buffer is freed, we set the line with the _set_line function
 * and we return the line, storing the return of the _set_line function
 * in a static variable, so that next time we call the get_next_line function
 * we have access to the first characters of the line that may have been read
 * before.
 * i.e. our file is "1\n234\n", our BUFFER_SIZE is 4
 * te first time we'll read through the file we'll read 1\n23
 * so what we are going to store in our static variable is '23', because the
 * next time we call the function on the same fd it will read 
 * starting at 4 in the
 * file.
 */
char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		return (NULL);
	line = _fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = _set_line(line);
	return (line);
}

/*
 * this function takes the liine buffer as parameter
 * it reads in eat until a \n or \0 is found
 * meaning the end of a line, or the end of the file
 * this function sets the line_buffer a \0 at the end of the line
 * inside of it and takes a substring of the buffer
 * from : the end of the line to : the end of the buffer
 * and returns this value as left_c
 */
static char	*_set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0)
		return (0);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (*left_c == 0)
	{
		free(left_c);
		left_c = NULL;
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}
/*
 * This function fill the "line" buffer
 * it will read BUFFER_SIZE characters in each iteration until
 * there is a \n character in the line buffer
 * each time through it will check if there is already data
 * in the left_c buffer and append the new characters to it
 * if a \n is found, it will return the left_c buffer 
 * after appending the read characters to it.
 */

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	b_read;
	char	*tmp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(left_c);
			return (0);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		tmp = left_c;
		left_c = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
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
