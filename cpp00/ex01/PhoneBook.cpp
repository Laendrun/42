/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:04:27 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 12:12:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _size(0), _oldest(0)
{
	std::cout << "PhoneBook Constructor called" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook Destructor called" << std::endl;
	return ;
}

void PhoneBook::createCT
(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNum,
	std::string secret
)
{
	if (this->_size < 8)
	{
		this->_contacts[this->_size].save
		(
			firstName,
			lastName,
			nickName,
			phoneNum,
			secret
		);
		this->_size++;
	}
	else
	{
		this->_contacts[this->_oldest].save
		(
			firstName,
			lastName,
			nickName,
			phoneNum,
			secret
		);
		this->_oldest = (this->_oldest + 1) % 8;
	}
}
//this->_oldest = this->_oldest + 1; this would work only if we don't add more than 8 contacts

void	PhoneBook::print(void)
{
	for (int i = 0; i < this->_size; i++)
		this->_contacts[i].printShort(i);
}

int	PhoneBook::get_size(void)
{
	return (this->_size);
}

void	PhoneBook::print_index_short(int index)
{
	this->_contacts[index].printShort(index);
}
