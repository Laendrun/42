/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:53:48 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 10:45:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>
# define _RESET "\e[0m"
# define _RED "\e[31m"
# define _GREEN "\e[32m"

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
		Zombie*	newZombie(std::string name);
	private:
		std::string name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif