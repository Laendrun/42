/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:54:18 by saeby             #+#    #+#             */
/*   Updated: 2022/11/01 21:34:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int _isprint(unsigned char c);

int ft_print_c(int c, t_flags *flags)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (!_isprint((unsigned char) c))
		return (1);
	if (flags->minus && flags->width > 0)
	{
		count += write(1, &c, 1);
		while (i < flags->width - 1)
		{
			count += write(1, " ", 1);
			i++;
		}
	}
	else if (flags->minus == 0 && flags->width > 0)
	{
		while (i < flags->width - 1)
		{
			count += write(1, " ", 1);
			i++;
		}
		count += write(1, &c, 1);
	}
	else
		count += write(1, &c, 1);
	/*if (write(1, &c, 1) == -1)
		return (-1);
	*/
	return (count);
}

static	int _isprint(unsigned char c)
{
	if ((c >= 32 && c <= 126) || (c >= 9 && c <= 11))
		return (1);
	return (0);
}