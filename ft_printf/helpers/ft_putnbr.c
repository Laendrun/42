/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:39:00 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 12:39:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nb < 0)
	{
		count += ft_print_c('-');
		nb = -nb;
		count += ft_putnbr(nb);
	}
	else
	{
		if (nb >= 10)
		{
			count += ft_putnbr(nb / 10);
			count += ft_putnbr(nb % 10);
		}
		else
			count += ft_print_c(nb + 48);
	}
	if (count < 0)
		return (-1);
	return (count);
}
