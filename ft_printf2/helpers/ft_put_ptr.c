/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:12:58 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 18:13:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(uintptr_t nbr)
{
	char	*chars;
	int		count;

	chars = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
	{
		count += ft_put_ptr(nbr / 16);
		count += ft_put_ptr(nbr % 16);
	}
	else
		count += ft_putchar(chars[nbr]);
	if (count < 0)
		return (-1);
	return (count);
}
