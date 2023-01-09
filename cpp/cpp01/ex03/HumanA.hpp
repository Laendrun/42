/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:39:04 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 21:31:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP
# include "Weapon.hpp"
# include <iostream>

class HumanA
{
	public:
				HumanA(std::string name, Weapon& weapon);
				~HumanA(void);
		void	attack();
	private:
		std::string	name;
		Weapon&		weapon;
};

#endif