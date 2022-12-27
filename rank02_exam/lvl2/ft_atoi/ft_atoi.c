/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:14:51 by saeby             #+#    #+#             */
/*   Updated: 2022/12/08 19:36:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13 ) || c == 32 ? 1 : 0);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57 ? 1 : 0);
}

int	ft_atoi(const char *str)
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