/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:28:28 by saeby             #+#    #+#             */
/*   Updated: 2022/11/12 23:10:25 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_d(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		count += ft_print_s("-2147483648");
	else if (nb < 0)
	{
		count += ft_print_c('-');
		nb = -nb;
		count += ft_print_d(nb);
	}
	else
	{
		if (nb >= 10)
		{
			count += ft_print_d(nb / 10);
			count += ft_print_d(nb % 10);
		}
		else
			count += ft_print_c(nb + 48);
	}
	if (count < 0)
		return (-1);
	return (count);
}
