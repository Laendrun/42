/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:52:23 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 15:59:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact Constructor called" << std::endl;

	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact Destructor called" << std::endl;
	return ;
}

void	Contact::save
(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNum,
	std::string secret
)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickName;
	this->_phoneNum = phoneNum;
	this->_secret = secret;
};

void	Contact::print_short(int index)
{
	// "|   Index    | First Name | Last Name  | Nick Name  |"
	std::cout << "| " << std::setw(10) << index + 1 << " | ";
	if (this->_firstName.length() > 10)
		std::cout << std::setw(10) << this->_firstName.substr(0, 9) + '.' << " | ";
	else
		std::cout << std::setw(10) << this->_firstName << " | ";
	if (this->_lastName.length() > 10)
		std::cout << std::setw(10) << this->_lastName.substr(0, 9) + '.' << " | ";
	else
		std::cout << std::setw(10) << this->_lastName << " | ";
	if (this->_lastName.length() > 10)
		std::cout << std::setw(10) << this->_nickName.substr(0, 9) + '.' << " | ";
	else
		std::cout << std::setw(10) << this->_nickName << " | ";
	std::cout << std::endl;
}

void	Contact::print_long(int index)
{
	// Index: 
	// Firstname: 
	// Lastname:
	// Nickname:
	// Phonenum:
	// Darkest secret:
	std::cout << "Index: " << index + 1 << std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nick name: " << this->_nickName << std::endl;
	std::cout << "Phone Num.: " << this->_phoneNum << std::endl;
	std::cout << "Darkest Secret: " << this->_secret << std::endl;
}
