/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 09:19:36 by saeby             #+#    #+#             */
/*   Updated: 2022/11/12 14:59:55 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc get_next_line.c get_next_line_utils.c test.c

#include "get_next_line.h"

int	main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	//fd2 = open("test2", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("++++++++++++++++++++++++++++\n");
	
	printf("%s", get_next_line(fd));
	printf("++++++++++++++++++++++++++++\n");
	
	return (0);
}
