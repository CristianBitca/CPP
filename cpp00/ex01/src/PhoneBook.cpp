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

void	PhoneBook::searchContact() const
{

}

void	PhoneBook::addContact()
{
	if (i == MAX_CONTACTS)
		i = 0;
	contact[i].addData();
	i++;
}

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
	i = 0;

	while (1)
	{
		switch (parsecommands())
		{
			case ADD:
				addContact();
				break;
			case SEARCH:	
				searchContact();
				break;
			case EXIT:
				return;
			default:
				break;
		}
	}
}