/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:00:33 by saeby             #+#    #+#             */
/*   Updated: 2023/01/01 19:45:11 by saeby            ###   ########.fr       */
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
	ft_printf("Welcome my this little UNIX world.\n");
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
		exit(0);
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
	static int	endmess = 0;

	if (!message)
		message = ft_strdup("");
	c = mt_s_handle_bit(c, signum, counter);
	counter++;
	if (counter == 8)
	{
		message = mt_strjoin(message, c);
		if (!c && !endmess)
			message = mt_s_handle_mess(&message, &endmess);
		else if (!c && endmess)
			message = mt_s_handle_rece(&message, &endmess);
		counter = 0;
		c = 0;
	}
}

char	*mt_s_handle_mess(char **message, int *endmess)
{
	*endmess += 1;
	ft_printf("%s", *message);
	free(*message);
	*message = NULL;
	return (*message);
}

char	*mt_s_handle_rece(char **message, int *endmess)
{
	mt_s_send_receipt(ft_atoi(*message), "Message Received.");
	free(*message);
	*message = NULL;
	*endmess = 0;
	return (*message);
}
