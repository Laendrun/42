/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:38:49 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 20:39:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_put_ptr(unsigned int adr);

int	ft_print_p(unsigned int adr)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_put_ptr(adr);
	return (count);
}

static int	ft_put_ptr(unsigned int adr)
{
	int	count;

	count = 0;
	if (adr >= 16)
	{
		count += ft_put_ptr(adr / 16);
		count += ft_put_ptr(adr % 16);
	}
	else
		count += ft_print_c("0123456789abcdef"[adr]);
	return (count);
}
