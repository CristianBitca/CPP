/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:11:58 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/03 17:12:00 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

commands PhoneBook::parsecommands()
{
	std::string	input;
	std::cout << "Input" << std::endl;
	std::getline(std::cin, input);
	if (input == "ADD")
		return(ADD);
	if (input == "SEARCH")
		return(SEARCH);
	if (input == "EXIT")
		return(EXIT);
	return UNKNOWN;
}

PhoneBook::PhoneBook()
{
	while (1)
	{
		switch (parsecommands())
		{
			case ADD:
				std::cout << "ADD" << std::endl;
				break;
			case SEARCH:	
				std::cout << "SEARCH" << std::endl;
				break;
			case EXIT:
				return;
			default:
				break;
		}
	}
}