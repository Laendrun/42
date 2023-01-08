/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:51:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 15:28:23 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/** @struct s_philo
 *  @brief This structure contains the required information
 *  for each philosopher
 *  @var ph_id
 *  ph_id contains the philosopher id
 *  @var ph_die
 *  ph_die contains the number of ms it takes to die
 *  @var ph_eat
 *  ph_eat contains the number of ms it takes to eat
 *  @var ph_sleep
 *  ph_sleep contains the number of ms it takes to sleep
 *  @var ph_last_meal
 *  ph_sleep contains the time from the last meal of the philosopher
 *  @var ph_status
 *  ph_status contains what the philosopher has to do
 *  0: needs to eat
 *  1: needs to sleep
 *  2: needs to think
 *  @var ph_goal
 *  ph_goal contains the number of meal the philosopher has to eat
 *  @var ph_total
 *  ph_total contains the total number of philosophers around the table
 *  @var fork
 *  fork is the philosopher's fork
 *  0: the fork is unavailable
 *  1: the fork is available
 *  @var forks
 *  forks is the number of forks the philosopher currently has
 *  @var stop
 *  stop is a pointer to the shared stop variable
 *  @var goal_reached
 *  goal_reached is a pointer to the shared goal_reached variable
 *  @var fork_m
 *  fork_m is the mutex locked when accessing the fork
 */
typedef struct s_philo
{
	int				ph_id;
	int				ph_die;
	int				ph_eat;
	int				ph_sleep;
	int				ph_last_meal;
	int				ph_status;
	int				ph_goal;
	int				ph_total;
	int				fork;
	int				forks;
	int				*stop;
	int				*goal_reached;
	pthread_mutex_t	*fork_m;
}	t_philo;

typedef struct s_args
{
	t_philo	*ph1;
	t_philo	*ph2;
}	t_args;

// main.c

// =====================
// init.c - 4
// =====================

/** @fn int	ph_init(t_philo *philos, char **av, int ac);
 *  @brief ph_init() initiate the correct number of 
 *  philosophers with default values for a part of the values
 *  @param philos is an array of t_philo that will contain all philos
 *  @param av is the *argv[] array
 *  @param ac is the main argument count (argc)
 *  @retval 1 on error
 *  @retval 0 on success
 */
int		ph_init(t_philo *philos, char **av, int ac, int *stop);

/** @fn int		ph_t_init(pthread_t *th, int nbr, t_philo *philos);
 *  @brief ph_t_init() initiate the correct number of threads
 *  => basically one per philosophers
 *  @param th is an array of pthread_t that will contain all threads
 *  @param nbr is the number of threads to create
 *  @param philos is the array of philosophers created with ph_init()
 *  @retval 1 on error
 *  @retval 0 on success
 */
int		ph_t_init(pthread_t *th, int nbr, t_philo *philos);

/** @fn void	ph_set_goal(t_philo *philos, int *goal_reached);
 *  @brief ph_set_goal() sets the goal pointer to the shared
 *  goal variable that is used to check if all the philosophers
 *  have eaten the required amount of time
 *  @param philos is the array containing all the philosophers
 *  @param goal_reached is an int pointer to the shared goal_reached variable
 */
void	ph_set_goal(t_philo *philos, int *goal_reached);

/** @fn void	ph_set_times(t_philo *philos, char **av);
 *  @brief ph_set_times() initiate the different times for each philosophers
 *  @param philos is the array containing all the philosophers
 *  @param av is the *argv[] parameter received in main()
 */
void	ph_set_times(t_philo *philos, char **av);

// =====================
// utils.c - 4
// =====================

/** @fn void	ph_free(t_philo *philos, int nbr);
 *  @brief ph_free() frees the allocated memory and destroy the mutexes
 *  @param philos is the array of all philos
 *  @param nbr is the number of philosophers in the array
 */
void	ph_free(t_philo *philos, int nbr);

/** @fn void	ph_print(t_philo *philos, int nbr);
 *  @brief ph_print() is a debugging function that prints all 
 *  values of each philo
 *  @param philos is the array of all philos
 *  @param nbr is the number of philosophers in the array
 */
void	ph_print(t_philo *philos, int nbr);

/** @fn void	ph_terminate(t_philo *philos, pthread_t *threads, int nbr);
 *  @brief ph_terminate() is a function that takes care of freeing memory
 *  and destroying mutexes, basically takes car of memory leaks
 *  @param philos is the array of all philosophers
 *  @param threads is the array of all threads
 *  @param nbr is the number of philosophers
 */
int		ph_terminate(t_philo *philos, pthread_t *threads, int nbr);

/** @fn int	ph_time(void);
 *  @brief ph_time() gives back the current time in ms of the running program
 *  @retval the number of ms elapsed since the first call to ph_time()
 */
int		ph_time(void);

// =====================
// routine.c - 5
// =====================

/** @fn void	*routine(void *philo);
 *  @brief routine is the routine function that handles everything a philo
 *  has to do (eating, thinking, sleeping, etc)
 *  @param philo is the corresponding philo (i.e. philos[1])
 */
void	*routine(void *philo);

/** @fn void	ph_die(t_philo *philo);
 *  @brief ph_die() checks if the philosopher should be dead or not
 *  @param philo is the array containing all the philosophers
 */
void	ph_die(t_philo *philo);

/** @fn void	ph_eat(t_philo *philo, t_philo *other);
 *  @brief ph_eat() manages the eating of the philosopher philo
 *  @param philo is the current philosopher
 *  @param other is the philosopher on the left of philo
 */
void	ph_eat(t_philo *philo, t_philo *other);

/** @fn void	ph_sleep(t_philo *philo);
 *  @brief ph_sleep() manages the sleeping of the philosopher philo
 *  @param philo is the current philosopher
 */
void	ph_sleep(t_philo *philo);

/** @fn void	ph_think(t_philo *philo, t_philo *other);
 *  @brief ph_think() manages the thinking of the philosopher philo
 *  as well as taking the required forks to eat
 *  @param philo is the current philosopher
 *  @param other is the philosopher on the left of philo
 */
void	ph_think(t_philo *philo, t_philo *other);

// =====================
// routine_utils.c - 3
// =====================

/** @fn void	ph_take_forks(t_philo *philo, t_philo *other);
 *  @brief ph_take_forks() tries to take the fork from the current philo
 *  and the philosopher on its left
 *  @param philo is the current philosopher
 *  @param other is the philosopher on the left of philo
 */
void	ph_take_forks(t_philo *philo, t_philo *other);

/** @fn void	ph_drop_forks(t_philo *philo, t_philo *other);
 *  @brief ph_drop_forks() drops all the forks used by philo
 *  @param philo is the current philosopher
 *  @param other is the philosopher on the left of philo
 */
void	ph_drop_forks(t_philo *philo, t_philo *other);

/** @fn void	ph_goal(t_philo *philo);
 *  @brief ph_goal() checks if the meal goal is reached for the philosopher
 *  @param philo is the current philosopher
 */
void	ph_goal(t_philo *philo);

// =====================
// helpers/ - 3
// =====================

/** @fn size_t	ft_strlen(const char *s);
 *  @brief ft_strlen returns the length of the null terminated string s
 *  @param s is a null terminated string
 *  @retval length of the string
 */
size_t	ft_strlen(const char *s);

/** @fn int	ft_atoi(const char *str);
 *  @brief ft_atoi converts the initial portion of the string pointed to by
 *  str to its int representation
 *  @param str is the string to convert
 *  @retval the int represention of str
 */
int		ft_atoi(const char *str);

/** @fn int	ft_isspace(int c);
 *  @brief ft_isspace checks if the character c is a space character
 *  The following are space characters:
 *  ` `, `\t`, `\r`, `\n`, `\v`, `\f`
 *  @param c is the character to check
 *  @retval 0 if c is not a space
 *  @retval 1 if c is a space
 */
int		ft_isspace(int c);

#endif