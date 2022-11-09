/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:48:45 by saeby             #+#    #+#             */
/*   Updated: 2022/11/04 15:45:13 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if character is not printable, print nothing but count the char as printed
// i.e. printf("%c %c %c\n", '0', 0, '1') prints "0  1" and returns 6

int main(void)
{
	//int i = -1;

	//printf("%d\n", ft_printf(" %-4p ", -10));
	ft_printf("|%25X|\n", 0x15ab58);

}