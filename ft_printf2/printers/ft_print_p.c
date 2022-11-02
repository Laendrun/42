/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:12:12 by saeby             #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2022/11/01 21:28:58 by saeby            ###   ########.fr       */
=======
/*   Updated: 2022/11/01 18:15:06 by saeby            ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_adr_len(unsigned int nb);

int	ft_print_p(int tmp, t_flags *flags)
{
<<<<<<< Updated upstream
	int	count;
	int	i;
	int	adr_len;
	
=======
	int		count;
	int		i;
	int		adr_len;
	uintptr_t	adr;
	(void) flags;

	/*if (tmp < 0)
		return (0);
	*/adr = (uintptr_t) tmp;
>>>>>>> Stashed changes
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
