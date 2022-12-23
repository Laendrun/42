/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:23:39 by saeby             #+#    #+#             */
/*   Updated: 2022/12/08 18:37:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char *av[])
{
	if (ac == 4)
	{
		switch(av[2][0])
		{
			case '+':
				printf("%d", atoi(av[1]) + atoi(av[3]));
				break;
			case '-':
				printf("%d", atoi(av[1]) - atoi(av[3]));
				break;
			case '*':
				printf("%d", atoi(av[1]) * atoi(av[3]));
				break;
			case '/':
				printf("%d", atoi(av[1]) / atoi(av[3]));
				break;
			case '%':
				printf("%d", atoi(av[1]) % atoi(av[3]));
				break;
		}
	}
	printf("\n");
}