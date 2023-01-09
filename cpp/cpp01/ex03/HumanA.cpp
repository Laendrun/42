/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:42:03 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 21:31:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << "HumanA consructor for " << this->name << " with weapon " << this->weapon.getType() << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA destructor for " << this->name << " with weapon " << this->weapon.getType() << std::endl;
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
	return ;
}