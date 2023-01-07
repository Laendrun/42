/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:51:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 13:35:43 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// ./philo 800 200 200 => will run int_max milliseconds

// status: 0 => needs to eat, 1 => needs to sleep, 2 => needs to think
typedef struct s_philo
{
	int				ph_id;
	int				ph_die;
	int				ph_eat;
	int				ph_sleep;
	int				ph_last_meal;
	int				ph_status;
	int				ph_dead;
	int				ph_goal;
	int				ph_meals;
	int				ph_eating;
	pthread_mutex_t	*fork;
}	t_philo;

typedef struct s_args
{
	t_philo	*ph1;
	t_philo	*ph2;
}	t_args;

// main.c

// =====================
// init.c
// =====================

/* @fn int	ph_init(t_philo *philos, char **av, int ac);
 * ph_init() initiate the correct number of philosophers with default values
 * @param philos is an array of t_philo that will contain all philos
 * @param av is the *argv[] array
 * @param ac is the main argument count (argc)
 * @retval 1 on error
 * @retval 0 on success
 */
int		ph_init(t_philo *philos, char **av, int ac);

/* ph_t_init() initiate the correct number of threads
 * => basically one per philosophers
 * @param th is an array of pthread_t that will contain all threads
 * @param nbr is the number of threads to create
 * @param philos is the array of philosophers created with ph_init()
 * @retval 1 on error
 * @retval 0 on success
 */
int		ph_t_init(pthread_t *th, int nbr, t_philo *philos);

// =====================
// utils.c
// =====================

/* ph_free() frees the allocated memory and destroy the mutexes
 * @param philos is the array of all philos
 * @param nbr is the number of philosophers in the array
 */
void	ph_free(t_philo *philos, int nbr);

/* ph_print() is a debugging function that prints all values of each philo
 * @param philos is the array of all philos
 * @param nbr is the number of philosophers in the array
 */
void	ph_print(t_philo *philos, int nbr);

/* ph_terminate() is a function that takes care of freeing memory
 * and destroying mutexes, basically takes car of memory leaks
 * @param philos is the array of all philosophers
 * @param threads is the array of all threads
 * @param nbr is the number of philosophers
 */
void	ph_terminate(t_philo *philos, pthread_t *threads, int nbr);

/* ph_time() gives back the current time in ms of the running program
 * @retval the number of ms elapsed since the first call to ph_time()
 */
int		ph_time(void);

// =====================
// routine.c
// =====================

/* routine is the routine function that handles everything a philo
 * has to do (eating, thinking, sleeping, etc)
 * @param philo is the corresponding philo (i.e. philos[1])
 */
void	*routine(void *philo);

void	ph_die(t_philo *philo);
void	ph_eat(t_philo *philo, t_philo *other);
void	ph_sleep(t_philo *philo);
void	ph_think(t_philo *philo);

// =====================
// helpers/
// =====================

/* ft_strlen returns the length of the null terminated string s
 * @param s is a null terminated string
 * @retval length of the string
 */
size_t	ft_strlen(const char *s);

/* ft_putstr_fd writes the null terminated string s to the file descriptor
 * fd
 * @param str is the null terminated string to write
 * @param fd is the file descriptor to write str to
 */
void	ft_putstr_fd(char *str, int fd);

/* ft_atoi converts the initial portion of the string pointed to by
 * str to its int representation
 * @param str is the string to convert
 * @retval the int represention of str
 */
int		ft_atoi(const char *str);

/* ft_isspace checks if the character c is a space character
 * The following are space characters:
 * ` `, `\t`, `\r`, `\n`, `\v`, `\f`
 * @param c is the character to check
 * @retval 0 if c is not a space
 * @retval 1 if c is a space
 */
int		ft_isspace(int c);

#endif