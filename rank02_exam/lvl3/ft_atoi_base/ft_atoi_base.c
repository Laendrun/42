/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 23:07:52 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 23:30:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(int c);
static int	ft_tolower(int c);
static int	ft_isbasechar(char c, int base);

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	res;

	if (str_base <= 1)
		return (0);
	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isbasechar(ft_tolower(str[i]), str_base) != -1)
	{
		res *= str_base;
		res += ft_isbasechar(ft_tolower(str[i]), str_base);
		i++;
	}
	res *= sign;
	return (res);
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13 ) || c == 32 ? 1 : 0);
}

static int	ft_tolower(int c)
{
	return ((c >= 65 && c <= 90) ? c + 32 : c);
}

static int	ft_isbasechar(char c, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (c == "0123456789abcdef"[i])
			return (i);
		i++;
	}
	return (-1);
}