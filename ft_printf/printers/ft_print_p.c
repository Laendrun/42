/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:10:58 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 12:37:28 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(uintptr_t adr)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(adr);
	if (count < -1)
		return (-1);
	return (count);
}
