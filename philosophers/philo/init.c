/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:47:41 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 21:08:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ph_init(t_philo *philos, char **av, int ac, int *stop)
{
	int	i;
	int	goal;

	goal = -1;
	if (ac == 6)
		goal = ft_atoi(av[5]);
	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].ph_id = i + 1;
		philos[i].ph_status = 2;
		philos[i].ph_goal = goal;
		philos[i].ph_total = ft_atoi(av[1]);
		philos[i].fork = 1;
		philos[i].forks = 0;
		philos[i].stop = stop;
		philos[i].fork_m = malloc(sizeof(pthread_mutex_t));
		if (!philos[i].fork_m)
			return (1);
		pthread_mutex_init(philos[i].fork_m, NULL);
		i++;
	}
	return (0);
}

void	ph_set_times(t_philo *philos, char **av)
{
	int	i;

	i = 0;
	while (i < ft_atoi(av[1]))
	{
		philos[i].ph_die = ft_atoi(av[2]);
		philos[i].ph_eat = ft_atoi(av[3]);
		philos[i].ph_sleep = ft_atoi(av[4]);
		philos[i].ph_last_meal = ph_time();
		i++;
	}
}

void	ph_set_goal(t_philo *philos, int *goal_reached)
{
	int	i;

	i = 0;
	while (i < philos[0].ph_total)
	{
		philos[i].goal_reached = goal_reached;
		i++;
	}
}

int	ph_t_init(pthread_t *th, int nbr, t_philo *philos)
{
	int		i;
	t_args	*args;

	i = 0;
	while (i < nbr)
	{
		args = malloc(sizeof(t_args));
		args->ph1 = &philos[i];
		if (i == 0)
			args->ph2 = &philos[nbr - 1];
		else
			args->ph2 = &philos[i - 1];
		if (pthread_create(&th[i], NULL, routine, (void *) args) != 0)
			return (1);
		i++;
	}
	return (0);
}
