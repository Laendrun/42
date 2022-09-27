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

static int	int_len(int nbr);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;

	len = int_len(n);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 2147483647)
		return ("2147483647");
	if (n == 0)
		return ("0");
	i = len - 1;
	while (n != 0)
	{
		result[i] = ((n % 10) + 48);
		n = n / 10;
		i--;
	}
	result[len] = '\0';
	return (result);
}

static int	int_len(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}
