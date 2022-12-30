/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:28:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/30 17:43:54 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	int	out_pipe[2];
	int	in_pipe[2];
	int	i;
	int	status;

	if (ac < 3)
		pip_error("Wrong number of argument.");
	if (access(av[1], R_OK) != 0)
		pip_error("infile not accessible in read mode.");

	if (pipe(in_pipe) == -1)
		pip_error("Error creating the pipe (1).");
	if (pipe(out_pipe) == -1)
		pip_error("Error creating the pipe (2).");

	in_pipe[0] = open(av[1], O_RDONLY);
	i = 0;
	while (i < ac - 3)
	{
		if (i % 2 == 0)
		{
			pip_new_first_process(av[i + 2], &in_pipe, &out_pipe, envp);
		}
		else
		{
			pip_new_second_process(av[i + 2], &in_pipe, &out_pipe, envp);
		}
		i++;
	}
	close(out_pipe[1]);
	close(in_pipe[1]);
	while (i > 0)
	{
		wait(&status);
		--i;
	}
	if ((ac % 2) == 0)
		pip_write(av[ac - 1], out_pipe[0]);
	else
		pip_write(av[ac - 1], in_pipe[0]);
	return (0);
}

void	pip_write(char *name, int fd_in)
{
	int	fd_out;
	int	b_read;
	char	buff[1];

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

void	pip_exec(char *bin, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	**paths;

	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	paths = pip_get_path(env);
	args = ft_split(bin, ' ');
	args[0] = pip_get_exec(args[0], paths);
	if (args[0])
		execve(args[0], args, env);
	pip_error("No bin file.");
}

void	pip_new_first_process(char *cmd, int (*ip)[2], int (*op)[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		pip_error("Error when forking (1).");
	if (pid == 0)
	{
		close((*ip)[1]);
		close((*op)[0]);
		pip_exec(cmd, (*ip)[0], (*op)[1], env);
	}
	close((*ip)[0]);
	close((*ip)[1]);
	pipe((*ip));
}

void	pip_new_second_process(char *cmd, int (*ip)[2], int (*op)[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		pip_error("Error when forking (1).");
	if (pid == 0)
	{
		close((*ip)[0]);
		close((*op)[1]);
		pip_exec(cmd, (*op)[0], (*ip)[1], env);
	}
	close((*op)[0]);
	close((*op)[1]);
	pipe((*op));
}
