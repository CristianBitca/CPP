/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conact.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:32:24 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/18 16:33:00 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

bool	Contact::empty()	const
{
	if (firstName.empty())
		return true;
	return false;
}

std::string Contact::format(std::string data)	const
{
    if (data.length() > 10)
        return data.substr(0, 9) + ".";
    return data;
}

void    Contact::printFormat(int width, int data)	const
{
    std::cout << std::setw(width) << data << "";
}

void    Contact::printFormat(int width, std::string data)	const
{
    std::cout << std::setw(width) << format(data) << " ";
}

void	Contact::printContact()	const
{
	if (firstName.empty())
		return ;
	std::cout << "Contact:" << std::endl;
	std::cout << "Firstname: " << firstName << std::endl;
	std::cout << "Lastname: " << lastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone: " << phone << std::endl;
	std::cout << "Secret: " << secret << std::endl;
}

void    Contact::printData(int index)    const
{
	if (firstName.empty())
		return ;
	printFormat(5, index);
	printFormat(10, firstName);
	printFormat(10, lastName);
	printFormat(10, Nickname);
	std::cout << std::endl;
}

void	Contact::parseData(std::string const msg, std::string	*data)
{
	do {
		std::cout << msg;
		parseInput(data);
	}	while (data->empty());
}

bool    Contact::addData()
{
	parseData(FIRSTNAME, &firstName);
    parseData(LASTNAME, &lastName);
	parseData(NICKNAME, &Nickname);
	parseData(PHONE, &phone);
	parseData(SECRET, &secret);
	if (checkPhone(phone)) {
		removeData();
		return false;
	}
	return true;
}

void	Contact::removeData()
{
	firstName.clear();
	lastName.clear();
	Nickname.clear();
	phone.clear();
	secret.clear();
}
