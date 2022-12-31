/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:27:36 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 16:15:50 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	pip_check_ac(int ac)
{
	if (ac < 5)
		pip_error("Wrong number of argument.");
}

// if av[1] => here_doc, read lines from stdin until we find only av[2] on line
int	pip_check_here_doc(char **av, int (*p)[2])
{
	int	fd_tmp;

	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		fd_tmp = STDIN_FILENO;
		if (fd_tmp >= 0)
			pip_read_here_d(av[2], fd_tmp, (*p)[1]);
		return (1);
	}
	else
	{
		(*p)[0] = open(av[1], O_RDONLY);
		return (0);
	}
}

//ft_strlen + 1 to check that there's nothing after the limiter in the line
void	pip_read_here_d(char *limiter, int fd_in, int fd_out)
{
	char	*line;
	char	*tmp;

	while (1)
	{
		line = get_next_line(fd_in);
		tmp = ft_strtrim(line, "\n");
		if (ft_strncmp(tmp, limiter, ft_strlen(limiter) + 1) == 0)
		{
			free(tmp);
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd_out);
		free(tmp);
		free(line);
	}
}
