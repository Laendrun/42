/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 21:46:53 by saeby             #+#    #+#             */
/*   Updated: 2023/01/09 23:01:37 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#define _RESET "\e[0m"
#define _RED "\e[31m"
#define _REDB "\e[41m"
#define _GREEN "\e[32m"
#define _YELLOW "\e[33m"
#define _WHITE "\e[37m"

std::string	read_file(std::ifstream& file)
{
	std::string	tmp;
	char		c;

	while (file.get(c))
		tmp += c;
	return tmp;
}

std::string	search_replace(std::string str, std::string orig, std::string goal)
{
	std::string	replaced_string;
	size_t		curr_pos;
	size_t		prev_pos;

	prev_pos = 0;
	curr_pos = 0;
	curr_pos = str.find(orig, curr_pos);
	while (curr_pos != std::string::npos)
	{
		while (prev_pos < curr_pos)
			replaced_string += str[prev_pos++];
		replaced_string += goal;
		curr_pos += orig.length();
		prev_pos = curr_pos;
		curr_pos = str.find(orig, curr_pos);
	}
	replaced_string += str[prev_pos];
	return (replaced_string);
}

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfile_name;
	std::string		if_content;
	if (ac != 4)
	{
		std::cout << _REDB << "Wrong number of argument !" << _RESET << std::endl;
		std::cout << _REDB << "Usage:" << _RESET << " ./sed <filename> <s1> <s2>" << _RESET << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile.fail())
	{
		std::cout << _REDB << "Unable to open the file:" << _RESET << " " << av[1] << std::endl;
		return (1);
	}
	outfile_name = av[1] + (std::string)".replace";
	outfile.open(outfile_name);

	if_content = read_file(infile);
	outfile << search_replace(if_content, av[2], av[3]);

	infile.close();
	outfile.close();
	return (0);
}
