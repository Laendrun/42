/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:10:58 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 10:41:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(uintptr_t adr)
{
	int	count;

	(void) adr;
	count = 0;
	count += ft_print_s("0x");
	count += ft_put_ptr(adr);
	return (count);
}
