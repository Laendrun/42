/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:12:12 by saeby             #+#    #+#             */
/*   Updated: 2022/11/01 17:23:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_adr_len(unsigned int nb);

int	ft_print_p(uintptr_t adr, t_flags *flags)
{
	int	count;
	int	i;
	int	adr_len;
	
	printf("%lu\n", adr);
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
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}
