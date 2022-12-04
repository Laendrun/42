/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:36:31 by saeby             #+#    #+#             */
/*   Updated: 2022/12/04 23:25:31 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_print_u(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 10)
	{
		count += ft_print_u(nb / 10);
		count += ft_print_u(nb % 10);
	}
	else
		count += ft_print_c(nb + 48);
	return (count);
}
