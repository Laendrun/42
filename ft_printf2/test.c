/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:48:45 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 20:15:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if character is not printable, print nothing but count the char as printed
// i.e. printf("%c %c %c\n", '0', 0, '1') prints "0  1" and returns 6

int main(void)
{
	int	i;
	
	ft_printf("Bliblablo\n");
	ft_printf("|||%-10c|||\n", 'K');\
	ft_printf("|||%10c|||\n", 'K');
	ft_printf("%%s %s\n", "Ceci est un test");
	ft_printf("%%u %u\n", 2147483652);
	ft_printf("%%%% %%\n");
	ft_printf("%% d 154: % d\n", 154);
	ft_printf("%%+ d 154: %+ d\n", 154);
	ft_printf("%%+d -154: %+d\n", -154);
	ft_printf("%%#X 154: %#X\n", 154);
	ft_printf("%%#x 154: %#x\n", 154);
	ft_printf("%%p &i: %p\n", &i);
	ft_printf("%%#X 0: %#X\n", 0);
}