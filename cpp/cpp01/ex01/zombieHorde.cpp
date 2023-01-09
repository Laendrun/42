/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:46:25 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 12:53:09 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	if (!horde)
		return (NULL);
	for (int i = 0; i < N; i++)
		horde[i].set_name(name);
	return (horde);
}