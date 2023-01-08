/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:52:23 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 12:34:18 by saeby            ###   ########.fr       */
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

void Contact::save
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

void Contact::printShort(int index)
{
	// "|   Index    | First Name | Last Name  | Nick Name  |"
	std::cout << "|     " << index << "      | ";
	std::cout << std::setw(10) << this->_firstName.substr(0, 9) + '.' << " | ";
	std::cout << std::setw(11) << this->_lastName.substr(0, 9) + '.' << " | ";
	std::cout << std::setw(11) << this->_nickName.substr(0, 9) + '.' << " |";
	std::cout << std::endl;
}
