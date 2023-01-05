/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:56:56 by saeby             #+#    #+#             */
/*   Updated: 2023/01/05 10:18:02 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	pthread_mutex_lock(&mutex);
	for (int i = 0; i < 10000000; i++)
		mails++;
	pthread_mutex_unlock(&mutex);
	return (0);
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	pthread_t	*forks;
	int			nbr_philo;

	nbr_philo = ft_atoi(av[1]);
	forks = malloc(nbr_philo * sizeof(pthread_t));
	//struct timeval tp;
	pthread_mutex_init(&mutex, NULL);

	for (int i = 0; i < nbr_philo; i++)
	{
		if (pthread_create(&forks[i], NULL, routine, NULL) != 0)
			return (1);
		printf("Thread %d started\n", i);
	}

	//gettimeofday(&tp, NULL);

	for (int i = 0; i < nbr_philo; i++)
	{
		if (pthread_join(forks[i], NULL) != 0) // => equivalent to the wait function for the processes
			return (11);
		printf("Thread %d finished\n", i);
	}
	pthread_mutex_destroy(&mutex);
	printf("Mails: %d\n", mails);
	//printf("%d / Mails: %d\n", tp.tv_usec, mails);
	return (0);
}
