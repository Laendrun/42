/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:54:18 by saeby             #+#    #+#             */
/*   Updated: 2022/11/02 16:45:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_c(int c, t_flags *flags)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	if (flags->minus && flags->width > 0)
	{
		count += write(1, &c, 1);
		while (i < flags->width - 1)
		{
			count += write(1, " ", 1);
			i++;
		}
	}
	else if (flags->minus == 0 && flags->width > 0)
	{
		while (i < flags->width - 1)
		{
			count += write(1, " ", 1);
			i++;
		}
		count += write(1, &c, 1);
	}
	else
		count += write(1, &c, 1);
	return (count);
}
