/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:50 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 13:42:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arguments)
{
	t_args	*args;
	int		start;

	// save start time and don't use usleep
	// usleep pauses everything so I can't check if the philosopher died

	args = (t_args *) arguments;
	while (!args->ph1->ph_dead)
	{
		start = ph_time();
		if (start - args->ph1->ph_last_meal > args->ph1->ph_die && !args->ph1->ph_eating)
		{
			args->ph1->ph_dead = 1;
			printf("%d %d died\n", start, args->ph1->ph_id);
			return (0);
		}
		if (args->ph1->ph_status == 0) // needs to eat
		{
			pthread_mutex_lock(args->ph1->fork);
			printf("%d %d has taken a fork\n", ph_time(), args->ph1->ph_id);
			pthread_mutex_lock(args->ph2->fork);
			args->ph1->ph_eating = 1;
			printf("%d %d has taken a fork\n", ph_time(), args->ph1->ph_id);
			printf("%d %d is eating\n", ph_time(), args->ph1->ph_id);
			while (ph_time() < start + args->ph1->ph_eat)
			args->ph1->ph_last_meal = start;
			args->ph1->ph_status = 1;
			args->ph1->ph_eating = 0;
			pthread_mutex_unlock(args->ph1->fork);
			pthread_mutex_unlock(args->ph2->fork);
		}
		else if (args->ph1->ph_status == 1) // needs to sleep
		{
			printf("%d %d is sleeping\n", ph_time(), args->ph1->ph_id);
			while (ph_time() < start + args->ph1->ph_sleep)
			args->ph1->ph_status = 2;
		}
		else if (args->ph1->ph_status == 2) // needs to think
		{
			printf("%d %d is thinking\n", ph_time(), args->ph1->ph_id);
			args->ph1->ph_status = 0;
		}
	}
	return (0);
}