/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:45:20 by saeby             #+#    #+#             */
/*   Updated: 2022/11/01 16:46:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnstr(char *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && i < n)
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}