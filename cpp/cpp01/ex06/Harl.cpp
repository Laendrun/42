/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:07:40 by saeby             #+#    #+#             */
/*   Updated: 2023/01/10 12:38:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl constructor called" << std::endl;
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Harl destructor called" << std::endl;
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

void	Harl::complain(std::string level, std::string filter)
{
	void		(Harl::*func[4])(void);
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	func[0] = &Harl::debug;
	func[1] = &Harl::info;
	func[2] = &Harl::warning;
	func[3] = &Harl::error;

	if (get_level(filter) < 0)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return ;
	}

	if (get_level(level) >= get_level(filter))
	{
		switch(get_level(level))
		{
			case 0:
				(this->*func[0])();
				break ;
			case 1:
				(this->*func[1])();
				break ;
			case 2:
				(this->*func[2])();
				break ;
			case 3:
				(this->*func[3])();
				break ;
		}
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;
	return ;
}

int	get_level(std::string level)
{
	if (level == "DEBUG")
		return (0);
	if (level == "INFO")
		return (1);
	if (level == "WARNING")
		return (2);
	if (level == "ERROR")
		return (3);
	return (-1);
}