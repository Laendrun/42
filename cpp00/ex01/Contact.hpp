/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:50:15 by saeby             #+#    #+#             */
/*   Updated: 2023/01/07 23:46:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void save
		(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNum,
			std::string secret
		);
		void printShort(int index);
	
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNum;
		std::string _secret;
};

#endif