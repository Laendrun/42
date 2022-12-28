/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:45:00 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 19:47:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check(int c, char *str, int index)
{
	int i;

	i = 0;
	while(i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return  (1);
}

int main(int argc, char **argv)
{	
	int i;
	int j;
	
	if (argc == 3)
	{
		i = 0;
		j = 0;
		while(argv[1][i])
			i++;
		while(argv[2][j])
		{
			argv[1][i] = argv[2][j];
			i++;
			j++;
		}
		i--;
		j = 0;
		while(j <= i)
		{
			if(check(argv[1][j], argv[1], j) == 1) 
				write (1, &argv[1][j], 1); 
			j++;
		}
	}
	write (1, "\n", 1);
}