/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 16:49:00 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 18:30:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_d(int nbr, t_flags *flags)
{
	int		count;
	(void)	flags;
	
	count = 0;
	if (nbr >= 0)
	{
		if ((flags->plus == 1) && (flags->space == 1))
			count += ft_putchar('+');
		else if ((flags->plus == 1) && (flags->space != 1))
			count += ft_putchar('+');
		else if ((flags->plus != 1) && (flags->space == 1))
			count += ft_putchar(' ');
	}
	count += ft_putnbr(nbr);
	if (count < 0)
		return (-1);
	return (count);
}
