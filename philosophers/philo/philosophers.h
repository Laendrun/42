/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:51:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/05 16:04:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// structures

typedef struct	s_philo
{
	int				ph_id;
	int				ph_die;
	int				ph_eat;
	int				ph_sleep;
	pthread_mutex_t	*fork;
}	t_philo;

// main.c

// init.c
int		ph_init(t_philo *philos, char **av);
int		ph_t_init(pthread_t *th, int nbr, t_philo *philos);

// utils.c
void	ph_free(t_philo *philos, int nbr);
void	ph_print(t_philo *philos, int nbr);
void	ph_terminate(t_philo *philos, pthread_t *threads, int nbr);

// routine.c
void	*routine(void *philo);

// helpers/
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);
int		ft_isspace(int c);

#endif