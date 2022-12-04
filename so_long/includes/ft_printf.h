/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:19:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/04 23:26:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>

int		ft_printf(const char *input_str, ...);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_p(uintptr_t adr);
int		ft_print_x(unsigned int nbr, int format);

#endif