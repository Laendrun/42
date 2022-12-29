/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:00:03 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 22:42:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static int	ft_atoi(char *str);
static int	ft_isdigit(int c);
static int	ft_isspace(int c);
static void	ft_putnbr(int n);
static int	ft_isprime(int n);

int	main(int ac, char *av[])
{
	int	sum;
	int	nb;

	nb = ft_atoi(av[1]);
	if (ac == 1 || nb < 0)
	{
		write(1, "0\n", 2);
		exit(1);
	}
	sum = 0;
	while (nb > 0)
	{
		if (ft_isprime(nb))
			sum += nb;
		nb--;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		n += 48;
		write(1, &n, 1);
	}
}

int	ft_isprime(int n)
{
	int	i;

	i = 3;
	if (n <= 1)
		return (0);
	if (((n % 2 == 0) && n > 2))
		return (0);
	while (i < (n / 2))
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13 ) || c == 32 ? 1 : 0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57 ? 1 : 0);
}

int	ft_atoi(char *str)
{
	int	res;
	int	i;
	int	s;

	res = 0;
	i = 0;
	s = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i] - 48;
		i++;
	}
	return (res *= s);
}