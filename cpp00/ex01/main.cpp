/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:41:04 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 14:25:20 by saeby            ###   ########.fr       */
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

void	contact_information(PhoneBook &pb, int i)
{
	pb.print_index_long(i);
}

void	search_prompt(PhoneBook &pb)
{
	int			i;
	std::string in;

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
	std::cout << "Enter contact index: ";
	while (1)
	{
		std::getline(std::cin, in);
		if (in == "EXIT")
			return ;
		else if ((in.length() != 1) || !(in[0] >= 49 && in[0] <= 58))
			std::cout << "Index is one digit between 1 - 8" << std::endl << "PhoneBook> ";
		else
			break ;
	}
	contact_information(pb, in[0] - 48 - 1);
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
	while (1)
	{
		std::cout << CLRSCR;
		std::cout << "Enter one of the following instruction (ALL CAPS)." << std::endl;
		std::cout << "ADD, SEARCH or EXIT" << std::endl;
		std::cout << "PhoneBook> ";
		std::getline(std::cin, input);
		if (input == "ADD")
			add_prompt(pb);
		else if (input == "SEARCH")
			search_prompt(pb);
		else if (input == "EXIT")
			return (0);
		std::cout << "PhoneBook> ";
	}
	return (0);
}