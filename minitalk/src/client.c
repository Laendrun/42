/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 15:55:22 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 19:04:35 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char **av)
{
	int	s_pid;

	if (ac < 3)
	{
		ft_printf("Wrong number of argument. ");
		ft_printf("Should be ./client <server pid> <message>.\n");
		exit(1);
	}
	s_pid = ft_atoi(av[1]);
	mt_c_send_message(s_pid, av[2]);
	return (0);
}

/* \e[1;1H\e[2J => printing this to the console will clear it
 * SIGUSR1 => sending 1
 * SIGUSR2 => sending 0
 * end of message condition is done by sending eight SIGUSR2
*/
void	mt_c_send_message(int pid, char *message)
{
	int				i;
	unsigned long	j;

	if (ft_strncmp(message, "CLR", 3) == 0)
		message = "\e[1;1H\e[2J";
	i = 0;
	j = 0;
	while (message[i])
	{
		while (j < 8 * sizeof(char))
		{
			if ((message[i] >> (7 - j)) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(50);
		}
		j = 0;
		i++;
	}
	mt_c_send_endmess(pid);
}
