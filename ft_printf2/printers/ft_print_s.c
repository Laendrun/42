/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:00:33 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 18:31:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s, t_flags *flags)
{
	int		i;
	char	*tmp;
	(void)	flags;

	i = 0;
	if (!s)
	{
		tmp = "(null)";
		while (tmp[i])
		{
			if (ft_putchar(tmp[i]) == -1)
				return (-1);
			i++;
		}
	}
	else
	{
		while (s[i])
		{
			if (ft_putchar(s[i]) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}