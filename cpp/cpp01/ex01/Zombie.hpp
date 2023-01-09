/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:53:48 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 13:08:25 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"
# define _YELLOW "\e[33m"

class Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		void	set_name(std::string name);
	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif