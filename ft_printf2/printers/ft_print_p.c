/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:12:12 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 18:31:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(uintptr_t adr, t_flags *flags)
{
	int	count;
	(void)	flags;

	count = 0;
	count += ft_putstr("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(adr);
	if (count < -1)
		return (-1);
	return (count);
}