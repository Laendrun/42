/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:50 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 17:55:26 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arguments)
{
	t_args	*args;

	args = (t_args *) arguments;
	while (!*(args->ph1->stop))
	{
		ph_goal(args->ph1);
		ph_die(args->ph1);
		if (args->ph1->ph_status == 0 && !*(args->ph1->stop)) // needs to eat
			ph_eat(args->ph1, args->ph2);
		else if (args->ph1->ph_status == 1 && !*(args->ph1->stop)) // needs to sleep
			ph_sleep(args->ph1);
		else if (args->ph1->ph_status == 2 && !*(args->ph1->stop)) // needs to think
			ph_think(args->ph1, args->ph2);
	}
	free(arguments);
	return (0);
}

void	ph_die(t_philo *philo)
{
	if (ph_time() - philo->ph_die > philo->ph_last_meal)
	{
		printf("%d %d died\n", ph_time(), philo->ph_id);
		*philo->stop = 1;
	}
}

void	ph_eat(t_philo *philo, t_philo *other)
{
	if (*(philo->stop))
		return ;
	printf("%d %d is eating\n", ph_time(), philo->ph_id);
	philo->ph_last_meal = ph_time();
	while (!*(philo->stop) && ph_time() < philo->ph_last_meal + philo->ph_eat)
		ph_die(philo);
	philo->ph_goal -= 1;
	ph_drop_forks(philo, other);
	philo->ph_status = 1;
}

void	ph_sleep(t_philo *philo)
{
	int	start;

	if (*(philo->stop))
		return ;
	start = ph_time();
	printf("%d %d is sleeping\n", ph_time(), philo->ph_id);
	while (!*(philo->stop) && ph_time() < start + philo->ph_sleep)
		ph_die(philo);
	philo->ph_status = 2;
}

void	ph_think(t_philo *philo, t_philo *other)
{
	if (*(philo->stop) || *(other->stop))
		return ;
	printf("%d %d is thinking\n", ph_time(), philo->ph_id);
	while (!*(philo->stop) && philo->forks != 2)
	{
		ph_take_forks(philo, other);
		ph_die(philo);
	}
	philo->ph_status = 0;
}

void	ph_take_forks(t_philo *philo, t_philo *other)
{
	if (*(philo->stop) || *(other->stop))
		return ;
	pthread_mutex_lock(philo->fork_m);
	if (philo->fork)
	{
		printf("%d %d has taken a fork\n", ph_time(), philo->ph_id);
		philo->fork = 0;
		philo->forks += 1;
	}
	pthread_mutex_unlock(philo->fork_m);
	pthread_mutex_lock(other->fork_m);
	if (other->fork)
	{
		printf("%d %d has taken a fork\n", ph_time(), philo->ph_id);
		other->fork = 0;
		philo->forks += 1;
	}
	pthread_mutex_unlock(other->fork_m);
}

void	ph_drop_forks(t_philo *philo, t_philo *other)
{
	if (*(philo->stop) || *(other->stop))
		return ;
	pthread_mutex_lock(philo->fork_m);
	philo->fork = 1;
	pthread_mutex_unlock(philo->fork_m);
	pthread_mutex_lock(other->fork_m);
	other->fork = 1;
	pthread_mutex_unlock(other->fork_m);
	philo->forks = 0;
}

void	ph_goal(t_philo *philo)
{
	if (philo->ph_goal < 0)
		return ;
	if (!philo->ph_goal)
		*philo->goal_reached += 1;
	if (*philo->goal_reached == philo->ph_total)
		*philo->stop = 1;
}
