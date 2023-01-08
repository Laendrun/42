/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 23:03:28 by saeby             #+#    #+#             */
/*   Updated: 2023/01/08 14:22:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	createCT
		(
			std::string firstName,
			std::string lastName,
			std::string nickName,
			std::string phoneNum,
			std::string secret
		);
		void	print_index_short(int index);
		void	print_index_long(int index);
		int		get_size(void);

	private:
		Contact	_contacts[8];
		int		_size;
		int		_oldest;
};

#endif