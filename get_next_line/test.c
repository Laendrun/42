/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:19:36 by saeby             #+#    #+#             */
/*   Updated: 2022/11/04 17:54:59 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	
	fd = open("test", O_RDONLY);
	//fd2 = open("test2", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("++++++++++++++++++++++++++++\n");
	printf("%s\n", get_next_line(fd));
	printf("++++++++++++++++++++++++++++\n");
	printf("%s\n", get_next_line(fd));
	printf("++++++++++++++++++++++++++++\n");
	printf("%s\n", get_next_line(fd));
	printf("++++++++++++++++++++++++++++\n");
	return (0);
}
