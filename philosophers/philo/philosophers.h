/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:51:30 by saeby             #+#    #+#             */
/*   Updated: 2023/01/02 16:32:53 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// main.c

// libft.c
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *str, int fd);
int		ft_atoi(const char *str);

// libft_utils.c
int		ft_isspace(int c);

// utils.c
int		ph_error(char *s);

#endif