/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:53:16 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 10:55:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

int	main(void)
{
	std::cout << "Creating a zombie from main... (on the stack)" << std::endl;
	// Stack Zombie
	Zombie z2("Test2");

	std::cout << "Creating a zombie from the newZombie function... (on the heap)" << std::endl;
	// Heap zombie
	Zombie*	z = newZombie("Test");
	
	z->announce();
	z2.announce();

	std::cout << "Creating a zombie and making it announce itself" << std::endl;
	randomChump("Random Guy");
	std::cout << "And... he's gone..." << std::endl;

	// deleting the zombie on the Heap
	std::cout << "Manually deleting heap zombie." << std::endl;
	delete(z);
	// same thing as free after using malloc in C
	return (0);
}