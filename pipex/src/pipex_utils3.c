/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:07:28 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 14:20:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pip_write_result(int ac, char **av, int (*op)[2], int (*ip)[2])
{
	// check for here_doc before writing out
	if ((ac % 2) == 0)
		pip_write(av[ac - 1], (*op)[0], 0);
	else
		pip_write(av[ac - 1], (*ip)[0], 0);
}
