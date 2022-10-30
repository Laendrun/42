/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:57:18 by saeby             #+#    #+#             */
/*   Updated: 2022/10/29 17:51:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @author saeby (saeby@42lausanne.ch)
 * @version 1.0
 * @date 2022-10-29
 */
#include "libft.h"

static int	int_len(long nbr);
static char	*pre_conv(int len);

/**
 * @fn char *ft_itoa(int n)
 * Converts an int to a string (char *)
 * @brief Converts an int to a string
 * @param n number to convert to string
 * @return char* 
 * @retval NULL If the memory allocation failed
 * @retval char* Number converted to string
 */
char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

/**
 * @fn static char *pre_conv(int len)
 * @param len length of the number that will be converted
 * @param len this length is the number of chars
 * @return char* allocated string in memory
 */
static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	else
	{
		tmp[0] = '0';
		return (tmp);
	}
}

/**
 * @fn static int int_len(long nbr)
 * @param nbr the number for which we want to count the 
 * @param nbr number of characters
 * @return int
 * @retval int The number of characters needed to write nbr
 */
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
