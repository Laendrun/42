/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 10:27:33 by saeby             #+#    #+#             */
/*   Updated: 2022/10/30 21:47:04 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input_str, ...)
{
	va_list	params;
	size_t	w_chars;
	char	curr_char;
	char	next_char;

	va_start(params, input_str);
	w_chars = 0;
	while (*input_str != 0)
	{
		curr_char = *input_str;
		next_char = *(input_str + 1);
		if (curr_char != '%')
			w_chars += ft_print_c(*input_str);
		else if (next_char == 'c')
		{
			w_chars += ft_print_c((char) va_arg(params, int));
			input_str++;
		}
		else if (next_char == 's')
		{
			w_chars += ft_print_s((char *) va_arg(params, char *));
			input_str++;
		}
		else if (next_char == 'd' || next_char == 'i')
		{
			w_chars += ft_print_d((int) va_arg(params, int));
			input_str++;
		}
		else if (next_char == '%')
		{
			w_chars += ft_print_c('%');
			input_str++;
		}
		else if (next_char == 'u')
		{
			w_chars += ft_print_u((unsigned int) va_arg(params, unsigned int));
			input_str++;
		}
		else if (next_char == 'p')
		{
			w_chars += ft_print_p((uintptr_t) va_arg(params, uintptr_t));
			input_str++;
		}
		else if (next_char == 'x' || next_char == 'X')
		{
			w_chars += ft_print_x((unsigned int) va_arg(params, unsigned int) \
			, next_char);
			input_str++;
		}
		input_str++;
	}
	va_end(params);
	return (w_chars);
}
