/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:29:15 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/10 16:56:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string	replace(std::string line, std::string s1, std::string s2)
{
	std::string	buffer;
	size_t	found;
	size_t	pos = 0;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		buffer += line.substr(pos, found - pos);
		buffer += s2;
		pos = found + s1.length();
	}
	buffer += line.substr(pos);
	return (buffer);
}

int	main(int argc, char **argv)
{
	if (argc != 4) {
		std::cout << "Exprecte next parameters ./replace <filename> <str1> <str2>" << std::endl;
		return 1;
	}
	
	std::string	filename = argv[1];
	std::string	filename_replace = filename + "_replace";
	std::string	str1 = argv[2];
	std::string	str2 = argv[3];

	if (str1.empty()) {
		std::cout << "Param str1 cannot be empty line" << std::endl;
		return 1;
	}

	std::ifstream	in_file(filename.c_str());
	if (!in_file) {
		std::cout << "Couldn't open the file " << filename << std::endl;
		return 1;  
	}

	std::ofstream	out_file(filename_replace.c_str());
	if (!out_file) {
		std::cout << "Couldn't create the file " << filename_replace << std::endl;
		return 1;
	}

	std::string	line;

	while(std::getline(in_file, line))
	{
		out_file << replace(line, str1, str2) << std::endl;
	}

	in_file.close();
	out_file.close();
	return 0;
}