/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 13:27:36 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 14:22:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_check_ac(int ac)
{
	if (ac < 5)
		pip_error("Wrong number of argument.");
}

void	pip_check_here_doc(char **av, int (*p)[2])
{
	// if av[1] => here_doc, read lines from stdin until we find only av[2] on line
	/*if (ft_strncmp(av[1], "here_doc", 8) == 0)
		(*p)[0] = STDIN_FILENO;
	else*/
		(*p)[0] = open(av[1], O_RDONLY);
}