/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:48:45 by saeby             #+#    #+#             */
/*   Updated: 2022/10/31 22:59:26 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if character is not printable, print nothing but count the char as printed
// i.e. printf("%c %c %c\n", '0', 0, '1') prints "0  1" and returns 6

int main(void)
{
	int	i;

	ft_printf("Bliblablo\n");
	ft_printf("|%-25c|\n", 'K');
	ft_printf("|%25c|\n", 'K');
	ft_printf("|%-c|\n", 'K');
	ft_printf("%s\n", "Ceci est un test");
	ft_printf("|%25s|\n", "Ceci est un test");
	ft_printf("|%-25s|\n", "Ceci est un test");
	ft_printf("|%10s|\n", "Ceci est un test");
	ft_printf("|%-10s|\n", "Ceci est un test");
	ft_printf("%u\n", 2147483652);
	ft_printf("%%\n");
	ft_printf("|% -5d|\n\n", 154);
	ft_printf("|%+ -5d|\n\n", 154);
	ft_printf("|%+010d|\n\n", 154);
	ft_printf("|%+-010d|\n\n", 154);
	ft_printf("|% d|\n\n", 154);
	ft_printf("|%+ d|\n\n", 154);
	ft_printf("|%+d|\n\n", -154);
	ft_printf("%#X\n", 154);
	ft_printf("%#x\n", 154);
	ft_printf("%p\n", &i);
	printf("|%#20p|\n", &i);
	ft_printf("%#X\n", 0);
}