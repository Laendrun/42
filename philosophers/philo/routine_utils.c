/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:32:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 18:33:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
