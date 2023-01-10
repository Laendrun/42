/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 23:04:01 by saeby             #+#    #+#             */
/*   Updated: 2023/01/10 08:27:08 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
		void	complain(std::string level, std::string filter);
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

int		get_level(std::string level);

#endif