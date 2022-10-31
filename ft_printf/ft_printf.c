/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:43:43 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 11:49:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %[parameter][flags][width][.precision][length]type

static int	_check_format(const char *input_str, va_list params, int i);

int	ft_printf(const char *input_str, ...)
{
	va_list	params;
	int		i;
	int		count;

	va_start(params, input_str);
	i = 0;
	count = 0;
	while (input_str[i])
	{
		if (input_str[i] == '%')
		{
			i++;
			count += _check_format(input_str, params, i);
		}
		else
			count += ft_print_c(input_str[i]);
		i++;
	}
	va_end(params);
	return (count);
}

static int	_check_format(const char *str, va_list par, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_c((char) va_arg(par, int));
	else if (str[i] == 's')
		count += ft_print_s((char *) va_arg(par, char *));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_d((int) va_arg(par, int));
	else if (str[i] == 'u')
		count += ft_print_u((unsigned int) va_arg(par, unsigned int));
	else if (str[i] == 'x' || str[i] == 'X')
		count += ft_print_x((unsigned int) va_arg(par, unsigned int), str[i]);
	else if (str[i] == 'p')
		count += ft_print_p((uintptr_t) va_arg(par, uintptr_t));
	else if (str[i] == '%')
		count += ft_print_c('%');
	return (count);
}