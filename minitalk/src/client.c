/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:55:22 by saeby             #+#    #+#             */
/*   Updated: 2023/01/01 18:53:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	struct sigaction	s_action;
	char				*c_pid;
	int					s_pid;

	if (ac < 3)
	{
		ft_printf("Wrong number of argument. ");
		ft_printf("Should be ./client <server pid> <message>.\n");
		exit(1);
	}
	s_action.sa_handler = mt_c_sighand;
	s_action.sa_flags = 0;
	s_pid = ft_atoi(av[1]);
	c_pid = ft_itoa(getpid());
	sigaction(SIGINT, &s_action, NULL);
	sigaction(SIGTERM, &s_action, NULL);
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	mt_send_message(s_pid, av[2]);
	mt_send_endmess(s_pid);
	mt_send_message(s_pid, c_pid);
	mt_send_endmess(s_pid);
	while (1)
		pause();
}

void	mt_c_sighand(int signum)
{
	if (signum == SIGINT || signum == SIGTERM)
		exit(0);
	if (signum == SIGUSR1 || signum == SIGUSR2)
		mt_c_receive_message(signum);
	else
		ft_printf("\nNon-supported signal received.\n");
}

// https://stackoverflow.com/questions/47981/
void	mt_c_receive_message(int signum)
{
	static char	*message;
	static int	counter = 0;
	static char	c;

	if (!message)
		message = ft_strdup("");
	if (signum == SIGUSR1)
		c |= 1 << (7 - counter);
	else if (signum == SIGUSR2)
		c |= 0 << (7 - counter);
	counter++;
	if (counter == 8)
	{
		message = mt_strjoin(message, c);
		if (!c)
		{
			ft_printf("%s", message);
			free(message);
			message = NULL;
		}
		counter = 0;
		c = 0;
	}
}
