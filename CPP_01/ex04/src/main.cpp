/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweizman <aweizman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:17:13 by antonweizma       #+#    #+#             */
/*   Updated: 2024/06/29 14:58:32 by aweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	replace(std::string old_str, std::string new_str, std::ofstream &outfile, std::ifstream &infile)
{
	std::string	line;
	// std::string	tmp;

	while (std::getline(infile, line))
	{
		size_t str_pos = 0;
		while ((str_pos = line.find(old_str)) != std::string::npos)
		{
			line = line.substr(0, str_pos) + new_str + line.substr(str_pos + old_str.length(), line.length());
		}
		outfile << line << std::endl;
	}
}

std::string get_outfile_name(std::string infile)
{
	size_t	dot_pos = infile.find('.');
	if (dot_pos == std::string::npos)
		return infile + ".replace";
	std::string outfile = infile.substr(0, dot_pos) + ".replace";
	return outfile;
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;

	if (argc != 4 || !argv)
		return (std::cout << "Wrong arguments.", 1);
	argv++;
	infile.open(argv[0]);
	if (!infile.is_open())
	{
		std::cerr << "Error opening infile: " << argv[0] << std::endl;
		if (infile.fail())
			std::cerr << "Error details: " << strerror(errno) << std::endl;
		return (1);
	}
	std::string infile_name(argv[0]);
	std::string	outfile_name = get_outfile_name(infile_name);
	outfile.open(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error creating outfile: " << outfile_name << std::endl;
		if (outfile.fail())
			std::cerr << "Error details: " << strerror(errno) << std::endl;
		infile.close();
		return (1);
	}
	replace(argv[1], argv[2], outfile, infile);
	outfile.close();
	infile.close();
	return (0);
}
