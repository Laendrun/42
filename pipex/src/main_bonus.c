/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:28:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 16:15:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int ac, char *av[], char *envp[])
{
	int	pipe1[2];
	int	pipe2[2];
	int	i;
	int	here_d;

	pip_check_ac(ac);
	pip_renew_pipe(&pipe1);
	pip_renew_pipe(&pipe2);
	here_d = pip_check_here_doc(av, &pipe2);
	i = 0;
	while (i < ac - here_d - 3)
	{
		if (i % 2 == 0)
			pip_new_f_process(av[i + here_d + 2], &pipe2, &pipe1, envp);
		else
			pip_new_s_process(av[i + here_d + 2], &pipe2, &pipe1, envp);
		i++;
	}
	pip_close_fd(pipe1[1], pipe2[1]);
	pip_wait_children(i);
	pip_write_result(ac, av, &pipe1, &pipe2);
	return (0);
}
