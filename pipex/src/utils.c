/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:35:28 by saeby             #+#    #+#             */
/*   Updated: 2022/12/29 20:43:47 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

char	*pip_get_path(char *s)
{
	char *tmp;

	tmp = ft_strjoin("/bin/", s);
	if (access(tmp, X_OK) == 0)
		return (tmp);
	tmp = ft_strjoin("/usr/bin/", s);
	if (access(tmp, X_OK) == 0)
		return (tmp);

	return (tmp);
}