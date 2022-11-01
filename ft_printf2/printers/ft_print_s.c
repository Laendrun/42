/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:00:33 by saeby             #+#    #+#             */
/*   Updated: 2022/11/01 13:52:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s, t_flags *flags)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!s && flags->width > 0 && flags->minus == 1)
	{
		count += ft_putstr("(null)");
		while (i++ < flags->width - 6)
			count += write(1, " ", 1);
	}
	else if (!s && flags->width > 0 && flags->minus == 0)
	{
		while (i++ < flags->width - 6)
			count += write(1, " ", 1);
		count += ft_putstr("(null)");
	}
	else if (!s && flags->width == 0 && flags->minus == 1)
		count += ft_putstr("(null)");
	else if (!s && flags->width == 0 && flags->minus == 0)
		count += ft_putstr("(null)");
	else if (s && flags->width > 0 && flags->minus == 1)
	{
		count += ft_putstr(s);
		while (i++ < flags->width - ft_strlen(s))
			count += write(1, " ", 1);
	}
	else if (s && flags->width > 0 && flags->minus == 0)
	{
		while (i++ < flags->width - ft_strlen(s))
			count += write(1, " ", 1);
		count += ft_putstr(s);
	}
	else
		count += ft_putstr(s);
	return (count);
}