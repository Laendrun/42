/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:48:41 by saeby             #+#    #+#             */
/*   Updated: 2022/11/01 16:09:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	_hex_len(int nb);
static int	_prepend_str(char *str);

int	ft_print_x(unsigned int nbr, int format, t_flags *flags)
{
	char	*chars;
	int		count;
	int		hex_len;
	int		i;

	if (format == 'x')
		chars = "0123456789abcdef";
	else 
		chars = "0123456789ABCDEF";

	count = 0;
	hex_len = _hex_len(nbr);
	if (flags->hash)
		hex_len += 2;
	i = 0;
	if (flags->hash)
	{
		if (flags->minus && flags->width > 0 && flags->zero)
		{
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			count += ft_put_hex(nbr, chars);
			while (i++ < flags->width - hex_len)
				count += write(1, " ", 1);
		}
		else if (flags->minus && flags->width > 0 && flags->zero == 0)
		{
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			count += ft_put_hex(nbr, chars);
			while (i++ < flags->width - hex_len)
				count += write(1, " ", 1);
		}
		else if (flags->minus && flags->width == 0 && flags->zero)
		{
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			count += ft_put_hex(nbr, chars);
		}
		else if (flags->minus && flags->width == 0 && flags->zero == 0)
		{
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			count += ft_put_hex(nbr, chars);
		}
		else if (flags->minus == 0 && flags->width > 0 && flags->zero)
		{
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			while (i++ < flags->width - hex_len)
				count += write(1, "0", 1);
			count += ft_put_hex(nbr, chars);
		}
		else if (flags->minus == 0 && flags->width > 0 && flags->zero == 0)
		{
			while (i++ < flags->width - hex_len)
				count += write(1, " ", 1);
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			count += ft_put_hex(nbr, chars);
		}
		else if (flags->minus == 0 && flags->width == 0 && flags->zero == 0)
		{
			if (format == 'x')
				count += _prepend_str("0x");
			else
				count += _prepend_str("0X");
			count += ft_put_hex(nbr, chars);
		}
		else
			count += ft_put_hex(nbr, chars);
	}
	else if (flags->hash == 0)
	{
		if (flags->minus && flags->width > 0 && flags->zero)
		{
			count += ft_put_hex(nbr, chars);
			while (i++ < flags->width - hex_len)
				count += write(1, " ", 1);
		}
		else if (flags->minus && flags->width > 0 && flags->zero == 0)
		{
			count += ft_put_hex(nbr, chars);
			while (i++ < flags->width - hex_len)
				count += write(1, " ", 1);
		}
		else if (flags->minus && flags->width == 0 && flags->zero)
			count += ft_put_hex(nbr, chars);
		else if (flags->minus && flags->width == 0 && flags->zero == 0)
			count += ft_put_hex(nbr, chars);
		else if (flags->minus == 0 && flags->width > 0 && flags->zero)
		{
			while (i++ < flags->width - hex_len)
				count += write(1, "0", 1);
			count += ft_put_hex(nbr, chars);
		}
		else if (flags->minus == 0 && flags->width > 0 && flags->zero == 0)
		{
			while (i++ < flags->width - hex_len)
				count += write(1, " ", 1);
			count += ft_put_hex(nbr, chars);
		}
		else
			count += ft_put_hex(nbr, chars);
	}
	else
		count += ft_put_hex(nbr, chars);
	return (count);
}

static int	_hex_len(int nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

static int	_prepend_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}
