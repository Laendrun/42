/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:07:53 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 10:42:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TEST
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# ifdef TEST
#  include <stdio.h>
# endif

int		ft_printf(const char *input_str, ...);
void	ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putunbr(unsigned int nb);
int		ft_put_ptr(uintptr_t nbr);
int		ft_put_hex(unsigned int nbr, char *chars);

int		ft_print_c(char c);
int		ft_print_s(char *str);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_p(uintptr_t adr);
int		ft_print_x(unsigned int nbr, int format);

#endif