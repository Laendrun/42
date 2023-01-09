/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:53:16 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 13:09:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "usage: ./ex01 <name> <quantity>" << std::endl;
		return (1);
	}

	std::string	name = av[1];
	int			N = std::atoi(av[2]);

	std::cout << _YELLOW << "Testing with a horde " << N << " zombies with name " << name << _RESET << std::endl;
	std::cout << _RED << "Spawning " << N << " zombies..." << _RESET << std::endl;
	Zombie	*horde = zombieHorde(N, name);

	std::cout << _YELLOW << "Each zombies will annouce themselves..." << _RESET << std::endl;
	for (int i = 0; i < N; i++)
		horde[i].announce();

	std::cout << _YELLOW << "I will now make them return into the ground..." << _RESET << std::endl;
	delete [] horde;
	return (0);
}