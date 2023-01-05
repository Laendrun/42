/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:41 by saeby             #+#    #+#             */
/*   Updated: 2023/01/05 16:02:27 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_init(t_philo *philos, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].ph_id = i + 1;
		philos[i].ph_die = ft_atoi(av[2]);
		philos[i].ph_eat = ft_atoi(av[3]);
		philos[i].ph_sleep = ft_atoi(av[4]);
		philos[i].fork = malloc(sizeof(pthread_mutex_t));
		if (!philos[i].fork)
			return (1);
		pthread_mutex_init(philos[i].fork, NULL);
		i++;
	}
	return (0);
}

int		ph_t_init(pthread_t *th, int nbr, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < nbr)
	{
		if (pthread_create(&th[i], NULL, routine, (void *) &philos[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}