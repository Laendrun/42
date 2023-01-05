/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:04:41 by saeby             #+#    #+#             */
/*   Updated: 2023/01/05 16:07:29 by saeby            ###   ########.fr       */
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
		i++;
	}
}

void	ph_free(t_philo *philos, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		pthread_mutex_destroy(philos[i].fork);
		free(philos[i].fork);
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