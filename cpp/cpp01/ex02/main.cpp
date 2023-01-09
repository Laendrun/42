/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:15:51 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 20:35:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define _RESET "\e[0m"
#define _RED "\e[31m"
#define _GREEN "\e[32m"
#define _YELLOW "\e[33m"
# define _CYAN "\e[36m"

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << _CYAN << "Let's print the addresses" << _RESET << std::endl << std::endl;

	std::cout << _GREEN << "Memory address of str:              " << _RESET <<
	_YELLOW << &str << _RESET << std::endl;

	std::cout << _GREEN << "Memory address stored in stringPTR: " <<
	_RESET << _YELLOW << stringPTR << _RESET << std::endl;

	std::cout << _GREEN << "Memory address stored in stringREF: " << _RESET <<
	_YELLOW << &stringREF << _RESET << std::endl << std::endl;

	std::cout << _CYAN << "Now, let's print the values" << _RESET << std::endl << std::endl;

	std::cout << _GREEN << "Value of str:                  " << _RESET <<
	_YELLOW << str << _RESET << std::endl;

	std::cout << _GREEN << "Value pointed to by stringPTR: " << _RESET <<
	_YELLOW << *stringPTR << _RESET << std::endl;

	std::cout << _GREEN << "Value pointed to by stringREF: " << _RESET <<
	_YELLOW << stringREF << _RESET << std::endl;
}