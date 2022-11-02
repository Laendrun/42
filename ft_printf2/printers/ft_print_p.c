/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:12:12 by saeby             #+#    #+#             */
/*   Updated: 2022/11/02 17:33:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_adr_len(unsigned int nb);

int	ft_print_p(long long tmp, t_flags *flags)
{
	int	count;
	int	i;
	int	adr_len;
	uintptr_t	adr;

	if (tmp < 0)
		return (0);
/*
	printf("long min: %ld ", LONG_MIN);
	printf("long max: %ld ", LONG_MAX);
	printf("long min: %lld ", LLONG_MIN);
	printf("long max: %lld ", LLONG_MAX);
*/
	adr = (uintptr_t) tmp;
	
	adr_len = _adr_len(adr) + 2;
	count = 0;
	i = 0;
	if (flags->minus && flags->width > 0)
	{
		count += ft_putstr("0x");
		count += ft_put_ptr(adr);
		while (i++ < flags->width - adr_len - 2)
			count += write(1, " ", 1);
	}
	else if (flags->minus && flags->width == 0)
	{
		count += ft_putstr("0x");
		count += ft_put_ptr(adr);
	}
	else if (flags->minus == 0 && flags->width > 0)
	{
		while (i++ < flags->width - adr_len - 2)
			count += write(1, " ", 1);
		count += ft_putstr("0x");
		count += ft_put_ptr(adr);
	}
	else 
		count += ft_putstr("0x");
		count += ft_put_ptr(adr);
	return (count);
}

static int	_adr_len(unsigned int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}
