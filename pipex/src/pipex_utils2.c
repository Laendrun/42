/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 20:40:06 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 14:21:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void	pip_write(char *name, int fd_in, int hd)
{
	int		fd_out;
	int		b_read;
	char	buff[1];
	(void) hd; // hd => 1 when here doc; hd => 0 when not here_doc
	if (access(name, F_OK) == 0)
		unlink(name);
	fd_out = open(name, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd_out < 0)
		pip_error("pip_write: unable to open outfile.");
	b_read = read(fd_in, &buff, sizeof(char));
	while (b_read > 0)
	{
		write(fd_out, &buff, 1);
		b_read = read(fd_in, &buff, sizeof(char));
	}
}

void	pip_close_fd(int fd1, int fd2)
{
	close(fd1);
	close(fd2);
}

void	pip_renew_pipe(int (*p)[2])
{
	pip_close_fd((*p)[0], (*p)[1]);
	pipe((*p));
}

void	pip_wait_children(int i)
{
	int	status;

	while (i-- > 0)
		wait(&status);
}
