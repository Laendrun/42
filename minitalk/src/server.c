/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:00:33 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 19:06:23 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	struct sigaction	s_action;
	pid_t				pid;

	s_action.sa_handler = mt_s_sighand;
	s_action.sa_flags = 0;
	pid = getpid();
	ft_printf("Welcome to this little world.\n");
	ft_printf("Server PID: %d\n", pid);
	sigaction(SIGINT, &s_action, NULL);
	sigaction(SIGTERM, &s_action, NULL);
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
	while (1)
		pause();
}

void	mt_s_sighand(int signum)
{
	if (signum == SIGINT || signum == SIGTERM)
	{
		ft_printf("\nKilling the server.\n");
		exit(0);
	}
	if (signum == SIGUSR1 || signum == SIGUSR2)
		mt_s_receive_message(signum);
	else
		ft_printf("\nNon-supported signal received.\n");
}

// https://stackoverflow.com/questions/47981/
void	mt_s_receive_message(int signum)
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
