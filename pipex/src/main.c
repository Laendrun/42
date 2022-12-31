/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:28:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 14:19:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	int	pipe1[2]; // out_pipe
	int	pipe2[2]; // in_pipe
	int	i;

	pip_check_ac(ac);
	pip_renew_pipe(&pipe1);
	pip_renew_pipe(&pipe2);
	pip_check_here_doc(av, &pipe2);
	i = 0;
	while (i < ac - 3)
	{
		if (i % 2 == 0)
			pip_new_f_process(av[i + 2], &pipe2, &pipe1, envp);
		else
			pip_new_s_process(av[i + 2], &pipe2, &pipe1, envp);
		i++;
	}
	pip_close_fd(pipe1[1], pipe2[1]);
	pip_wait_children(i);
	pip_write_result(ac, av, &pipe1, &pipe2);
	return (0);
}
