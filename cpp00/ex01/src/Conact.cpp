/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conact.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:32:24 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/03 17:32:25 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

void    Contact::printData()    const
{
    std::cout << firstName;
    std::cout << lastName;
    std::cout << Nickname;
    std::cout << phone;
    std::cout << secret << std::endl;
}

int	Contact::parseData(std::string	*data)
{
	int	count = 0;
	int maxAttempt = 3;

	while (count != maxAttempt)
	{
		std::getline(std::cin, *data);
		if (data->empty()) {
			std::cout << "Empty line" << std::endl;
			count++;
		} else
			return (0);
	}
	return (1);
}

void    Contact::addData()
{
	if (parseData(&firstName))
		return ;
    if (parseData(&lastName))
		return ;
	if (parseData(&Nickname))
		return ;
	if (parseData(&phone))
		return ;
	if (parseData(&secret))
		return ;
}

Contact::Contact ()
{
	
}