/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:35:28 by saeby             #+#    #+#             */
/*   Updated: 2023/01/01 17:03:54 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_exec(char *bin, int fd_in, int fd_out, char **env)
{
	char	**args;
	char	**paths;

	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	paths = pip_get_path(env);
	args = ft_split(bin, ' ');
	args[0] = pip_get_exec(args[0], paths);
	execve(args[0], args, env);
}

void	pip_new_f_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		pip_error("Error when forking (1).");
	if (pid == 0)
	{
		pip_close_fd((*p1)[1], (*p2)[0]);
		pip_exec(cmd, (*p1)[0], (*p2)[1], env);
	}
	pip_renew_pipe(p1);
}

void	pip_new_s_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		pip_error("Error when forking (1).");
	if (pid == 0)
	{
		pip_close_fd((*p1)[0], (*p2)[1]);
		pip_exec(cmd, (*p2)[0], (*p1)[1], env);
	}
	pip_renew_pipe(p2);
}

char	**pip_get_path(char **env)
{
	char	**paths;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	paths = ft_split(*env + 5, ':');
	return (paths);
}

char	*pip_get_exec(char *cmd, char **paths)
{
	char	*path;

	if ((ft_strncmp(cmd, "./", 2) == 0) \
		&& access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	pip_no_exec(cmd);
	return (NULL);
}
