/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:54:08 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 17:55:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void)
{
	std::cout << "Contact Constructor called" << std::endl;

	return ;
}

Zombie::~Zombie(void)
{
	std::cout << "Contact Destructor called" << std::endl;
	return ;
}