/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:06 by saeby             #+#    #+#             */
/*   Updated: 2022/12/27 16:41:43 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[])
{
	(void) ac;
	(void) av;
	if (ac != 5)
		pip_error("Wrong number of arguments");
	ft_printf("pipex is alive!\n");
	return (0);
}