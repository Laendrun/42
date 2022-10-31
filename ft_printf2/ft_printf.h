/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:49:21 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 19:07:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags
{
	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hash;
	int	total;
	int	width;
} t_flags;

int		ft_printf(const char *input_str, ...);

int 	ft_print_c(unsigned char c, t_flags *flags);
int		ft_print_d(int nbr, t_flags *flags);
int		ft_print_u(unsigned int nbr, t_flags *flags);
int		ft_print_x(unsigned int nbr, int format, t_flags *flags);
int		ft_print_s(char *s, t_flags *flags);
int		ft_print_p(uintptr_t adr, t_flags *flags);

int		ft_putchar(char c);
int		ft_putnbr(int nbr);
int		ft_putstr(char *s);
int		ft_putstr_sep(char *s);
char	*ft_itoa(int n);
int		ft_putunbr(unsigned int nb);
int		ft_put_hex(unsigned int nbr, char *chars);
int		ft_put_ptr(uintptr_t nbr);

#endif
