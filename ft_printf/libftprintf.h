/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:07:53 by saeby             #+#    #+#             */
/*   Updated: 2022/10/29 13:54:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEST

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# ifdef TEST
#  include <stdio.h>
# endif

int		ft_printf(const char *, ...);
void	ft_putchar(char);
int		ft_putnbr(int);

int		ft_print_c(char);
int		ft_print_s(char*);

#endif