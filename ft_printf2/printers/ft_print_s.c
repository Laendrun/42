/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:00:33 by saeby             #+#    #+#             */
/*   Updated: 2022/11/01 17:02:06 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s, t_flags *flags)
{
	int		i;
	int		count;
	int		prec;

	i = 0;
	count = 0;
	if (flags->point == 0)
	{
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
	}
	else
	{
		/*if (ft_strlen(s) >= flags->precision)
			prec = flags->precision;
		else
			prec = ft_strlen(s);*/
		if (!s && flags->width > 0 && flags->minus)
		{
			if (ft_strlen(s) >= flags->precision)
				prec = flags->precision;
			else
				prec = 6;
			count += ft_putnstr("(null)", flags->precision);
			while (i++ < flags->width - prec)
				count += write(1, " ", 1);
		}
		else if (!s && flags->width > 0 && flags->minus == 0)
		{
			if (ft_strlen(s) >= flags->precision)
				prec = flags->precision;
			else
				prec = 6;
			while (i++ < flags->width - prec)
				count += write(1, " ", 1);
			count += ft_putnstr("(null)", flags->precision);
		}
		else if (!s && flags->width == 0 && flags->minus == 1)
			count += ft_putnstr("(null)", flags->precision);
		else if (s && flags->width > 0 && flags->minus == 1)
		{
			if (ft_strlen(s) >= flags->precision)
				prec = flags->precision;
			else
				prec = ft_strlen(s);
			count += ft_putnstr(s, flags->precision);
			while (i++ < flags->width - prec)
				count += write(1, " ", 1);
		}
		else if (s && flags->width > 0 && flags->minus == 0)
		{
			if (ft_strlen(s) >= flags->precision)
				prec = flags->precision;
			else
				prec = ft_strlen(s);
			while (i++ < flags->width - ft_strlen(s))
				count += write(1, " ", 1);
			count += ft_putnstr(s, flags->precision);
		}
		else
			count += ft_putnstr(s, flags->precision);
	}
	return (count);
}