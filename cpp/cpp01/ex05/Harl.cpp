/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:07:40 by saeby             #+#    #+#             */
/*   Updated: 2023/01/10 12:44:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

// Constructor
Harl::Harl(void)
{
	return ;
}

// Destructor
Harl::~Harl(void)
{
	return ;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*func[4])(void);
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;

	for (size_t i = 0; i < levels->length(); i++)
	{
		if (level == levels[i])
		{	
			(this->*func[i])();
			return ;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}