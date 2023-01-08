/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 22:50:15 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 14:23:09 by saeby            ###   ########.fr       */
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
		void	save
		(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNum,
			std::string secret
		);
		void	print_short(int index);
		void	print_long(int index);
	
	private:
		std::string	_firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNum;
		std::string _secret;
};

#endif