/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:54:08 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 13:09:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// Constructors
Zombie::Zombie(void)
{
	std::cout << _GREEN << "Default Zombie Constructor called" << _RESET << std::endl;
	return ;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << _GREEN << "Zombie \"" << _RESET << this->name << _GREEN << "\" Constructor called" << _RESET << std::endl;
	return ;
}

// Destructor
Zombie::~Zombie(void)
{
	std::cout << _RED << "Zombie \"" << _RESET << this->name << _RED << "\" Destructor called" << _RESET << std::endl;
	return ;
}

// Member functions

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	return ;
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
	return ;
}