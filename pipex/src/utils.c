/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:35:28 by saeby             #+#    #+#             */
/*   Updated: 2022/12/30 12:29:08 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

char	*pip_get_exec(char *cmd, char **paths)
{
	char *path;

	/*path = ft_strjoin("/bin/", cmd);
	if (access(path, X_OK) == 0)
		return (path);
	path = ft_strjoin("/usr/bin/", path);
	if (access(path, X_OK) == 0)
		return (path);*/
	while (*paths)
	{
		path = ft_strjoin(*paths, "/");
		path = ft_strjoin(path, cmd);
		if (access(path, X_OK) == 0)
			return (path);
		paths++;
	}
	return (NULL);
}

char	**pip_get_path(char **env)
{
	char	**paths;
	char	**path;

	while (*env)
	{
		if (ft_strncmp(*env, "PATH", 4) == 0)
			break ;
		env++;
	}
	path = ft_split(*env, '=');
	paths = ft_split(path[1], ':');
	free(path[0]);
	free(path[1]);
	free(path);
	return (paths);
}
