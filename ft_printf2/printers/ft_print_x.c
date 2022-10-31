/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:48:41 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 18:31:36 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x(unsigned int nbr, int format, t_flags *flags)
{
	char	*chars;
	int		count;

	count = 0;
	if (nbr > 0)
	{
		if (flags->hash && format == 'x')
			count += ft_putstr("0x");
		else if (flags->hash && format == 'X')
			count += ft_putstr("0X");
	}
	if (format == 'x')
		chars = "0123456789abcdef";
	else
		chars = "0123456789ABCDEF";
	count += ft_put_hex(nbr, chars);
	return (count);
}
