/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:49:52 by saeby             #+#    #+#             */
/*   Updated: 2022/11/02 17:48:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_check_format(const char *input_str, va_list *params, int *i);
static void	_check_flags(char c, t_flags *flags);
static void	_initiate_flags(t_flags *flags);
static int	_isflag(char c);
static int	_isdigit(char c);

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
			count += _check_format(input_str, &params, &i);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += ft_putchar(input_str[i]);
			if (count < 0)
				return (-1);
		}
		i++;
	}
	va_end(params);
	return (count);
}

static int	_check_format(const char *str, va_list *par, int *i)
{
	int		count;
	int		width;
	t_flags	*flags;

	width = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (-1);
	_initiate_flags(flags);
	while (_isflag(str[*i]))
	{
		_check_flags(str[*i], flags);
		flags->total++;
		*i = *i + 1;
	}
	while(_isdigit(str[*i]))
	{
		flags->width *= 10;
		flags->width += str[*i] - 48;
		*i = *i + 1;
	}
	if (str[*i] == '.')
	{
		flags->point = 1;
		*i = *i + 1;
	}
	while (_isdigit(str[*i]))
	{
		flags->precision *= 10;
		flags->precision += str[*i] - 48;
		*i = *i + 1;
	}
	count = 0;
	if (str[*i] == 'c')
		count += ft_print_c((int) va_arg(*par, int), flags);
	else if (str[*i] == '%')
		count += ft_putchar('%');
	else if (str[*i] == 'd' || str[*i] == 'i')
		count += ft_print_d((int) va_arg(*par, int), flags);
	else if (str[*i] == 'u')
		count += ft_print_u((unsigned int) va_arg(*par, unsigned int), flags);
	else if (str[*i] == 's')
		count += ft_print_s((char *) va_arg(*par, char *), flags);
	else if (str[*i] == 'x' || str[*i] == 'X')
		count += ft_print_x((unsigned int) va_arg(*par, unsigned int), \
		str[*i], flags);
	else if (str[*i] == 'p' && !flags->minus)
		count += ft_print_p((long long) va_arg(*par, long long), flags);
	free(flags);
	return (count);
}

static void	_check_flags(char c, t_flags *flags)
{
	if (c == '-')
		flags->minus = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '#')
		flags->hash = 1;
}

static int	_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

static int	_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static void	_initiate_flags(t_flags *flags)
{
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->zero = 0;
	flags->total = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->point = 0;
	flags->precision = 0;
}