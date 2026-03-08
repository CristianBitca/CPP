/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:11:58 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/08 23:01:41 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"

void    PhoneBook::printHeader()	const
{
    std::cout << std::setw(5) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;
}

void	PhoneBook::printContacts() const
{
	int	id;

	id = 1;
	for (int i = 0; i < MAX_CONTACTS; i++) {
		contact[i].printData(id);
		id++;
	}
}

void	PhoneBook::searchContact() const
{
	int	index;
	std::string	input;

	if (contact[0].empty()) {
		std::cout << "Empty phone book" << std::endl;
		return ;
	}
	printHeader();
	printContacts();
	std::cout << "Enter ID: ";
	parseInput(&input);
	if ((input.length() != 1 || !isdigit(input[0]))){
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	index = atoi(input.c_str()) - 1;
	if (index < 0 || index >= 8 || contact[index].empty()){
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	contact[index].printContact();
}

void	PhoneBook::addContact()
{
	if (i == MAX_CONTACTS)
		i = 0;
	if (contact[i].addData())
		i++;
}

commands PhoneBook::parsecommands()
{
	std::string	input;
	std::cout << "Input" << std::endl;
	parseInput(&input);
	if (input == "ADD")
		return(ADD);
	if (input == "SEARCH")
		return(SEARCH);
	if (input == "EXIT")
		return(EXIT);
	return UNKNOWN;
}


void	PhoneBook::createPhoneBook()
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