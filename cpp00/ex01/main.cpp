/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:41:04 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 12:17:53 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"
#define PH_HEADER_0 "-----------------------------------------------------"
#define PH_HEADER_1 "|   Index    | First Name | Last Name  | Nick Name  |"
#define CLRSCR "\e[1;1H\e[2J"

void	manage_input(std::string *destination)
{
	std::string	in;

	while (1)
	{
		std::getline(std::cin, in);
		if (in.length() == 0)
		{
			std::cout << "Can't be empty" << std::endl;
			std::cout << "PhoneBook> ";
		}
		else
		{
			*destination = in;
			break ;
		}
	}
}

void	search_prompt(PhoneBook &pb)
{
	int	i;

	std::cout << CLRSCR;
	std::cout << PH_HEADER_0 << std::endl;
	std::cout << PH_HEADER_1 << std::endl;
	std::cout << PH_HEADER_0 << std::endl;
	i = 0;
	while (i < pb.get_size())
	{
		pb.print_index_short(i);
		i++;
	}
	std::cout << PH_HEADER_0 << std::endl;
}

void	add_prompt(PhoneBook &pb)
{
	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string se;
	std::cout << CLRSCR;
	std::cout << "Enter information for new contact:" << std::endl;
	std::cout << "First Name: ";
	manage_input(&fn);
	std::cout << "Last Name: ";
	manage_input(&ln);
	std::cout << "Nick Name: ";
	manage_input(&nn);
	std::cout << "Phone Number: ";
	manage_input(&pn);
	std::cout << "Darkest Secret: ";
	manage_input(&se);
	pb.createCT(fn, ln, nn, pn, se);
	return ;
}

int	main(void)
{
	PhoneBook	pb;
	std::string	input;
	std::cout << CLRSCR;
	std::cout << "Enter one of the following instruction (ALL CAPS)." << std::endl;
	std::cout << "ADD, SEARCH or EXIT" << std::endl;
	std::cout << "PhoneBook> ";
	while (1)
	{
		std::getline(std::cin, input);
		if (input == "ADD")
			add_prompt(pb);
		else if (input == "SEARCH")
			search_prompt(pb);
		else if (input == "EXIT")
			break ;
		std::cout << "PhoneBook> ";
	}
	return (0);
}