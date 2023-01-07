/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:04:41 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 18:31:45 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ph_print(t_philo *philos, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		write(1, "\n", 1);
		printf("Philo id     : %d\n", philos[i].ph_id);
		printf("Time to die  : %d\n", philos[i].ph_die);
		printf("Time to eat  : %d\n", philos[i].ph_eat);
		printf("Time to sleep: %d\n", philos[i].ph_sleep);
		printf("Last meal    : %d\n", philos[i].ph_last_meal);
		printf("Goal         : %d\n", philos[i].ph_goal);
		printf("Meals        : %d\n", philos[i].ph_meals);
		i++;
	}
}

void	ph_free(t_philo *philos, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(philos[i].fork_m);
		free(philos[i].fork_m);
		i++;
	}
	free(philos);
}

void	ph_terminate(t_philo *philos, pthread_t *threads, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
	ph_free(philos, nbr);
}

int	ph_time(void)
{
	struct timeval	time;
	static int		t = 0;

	gettimeofday(&time, NULL);
	if (t == 0)
		t = time.tv_sec;
	return (((time.tv_sec - t) * 1000) + (time.tv_usec / 1000));
}
