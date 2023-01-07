/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:55:50 by saeby             #+#    #+#             */
/*   Updated: 2023/01/05 16:57:55 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philo)
{
	printf("philo id: %d\n", ((t_philo *) philo)->ph_id);
	// before every status change, check if difference with last_meal is greater than ph_die
	// lock own fork + (philo - 1)'s fork
		// change status to eating
		// wait for ph_eat before going further
	// unlock forks
	// set status to sleeping
		// wait for ph_sleep before going further
	// set status to thinking
	// try to eat again if forks available
	return (0);
}