/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __test.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:16:41 by saeby             #+#    #+#             */
/*   Updated: 2022/11/09 11:08:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	int	i;

	write(1, "Test\n", 5);
	ft_printf("Testing ft_printf from libft.\n");
	ft_printf("%%%% : %%\n");
	ft_printf("%%d : %d\n", 1548);
	ft_printf("%%u : %u\n", 3147483648);
	ft_printf("%%c : %c\n", 'K');
	ft_printf("%%s : %s\n", "Je suis un test");
	ft_printf("%%x : %x\n", 0xabcd);
	ft_printf("%%x : %x\n", 1654);
	ft_printf("%%X : %X\n", 0xabcd);
	ft_printf("%%X : %X\n", 1654);
	ft_printf("%%p : %p\n", &i);
	return (0);
}