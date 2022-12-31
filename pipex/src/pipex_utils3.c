/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:07:28 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 15:33:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// check for here_doc before writing out
void	pip_write_result(int ac, char **av, int (*op)[2], int (*ip)[2])
{
	int	here_d;

	here_d = 0;
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
		here_d = 1;
	if (((ac - here_d) % 2) == 0)
		pip_write(av[ac - 1], (*op)[0], here_d);
	else
		pip_write(av[ac - 1], (*ip)[0], here_d);
}
