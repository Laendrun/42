/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:57:18 by saeby             #+#    #+#             */
/*   Updated: 2022/09/26 23:05:42 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static int	int_len(long nbr);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	int		s;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '0';
	if (nbr < 0)
	{
		s = 1;
		nbr = -nbr;
	}
	else
		s = 0;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (s)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

static int	int_len(long nbr)
{
	int	count;
	
	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}