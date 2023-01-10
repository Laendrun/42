/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:06:54 by saeby             #+#    #+#             */
/*   Updated: 2023/01/10 08:33:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	std::string filter;
	Harl		harl;

	if (ac == 1)
		filter = "DEBUG";
	if (ac == 2)
		filter = av[1];

	harl.complain("DEBUG", filter);
	harl.complain("INFO", filter);
	harl.complain("WARNING", filter);
	harl.complain("ERROR", filter);
	return (0);
}