/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 18:12:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/01 19:43:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*mt_strjoin(char *s, char c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *) malloc((ft_strlen(s) + 2 * sizeof(char)));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = c;
	res[i + 1] = 0;
	return (res);
}

void	mt_send_endmess(int pid)
{
	unsigned long	i;

	i = 0;
	while (i < 8 * sizeof(char))
	{
		kill(pid, SIGUSR2);
		usleep(50);
		i++;
	}
}

/* \e[1;1H\e[2J => printing this to the console will clear it
 * SIGUSR1 => sending 1
 * SIGUSR2 => sending 0
 * end of message condition is done by sending eight SIGUSR2
*/
void	mt_send_message(int pid, char *message)
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
}

char	mt_s_handle_bit(char c, int signum, int counter)
{
	if (signum == SIGUSR1)
		c |= 1 << (7 - counter);
	else if (signum == SIGUSR2)
		c |= 0 << (7 - counter);
	return (c);
}

void	mt_s_send_receipt(int c_pid, char *message)
{
	mt_send_message(c_pid, message);
	mt_send_endmess(c_pid);
	kill(c_pid, SIGINT);
}
