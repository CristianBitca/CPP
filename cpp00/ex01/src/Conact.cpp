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
    std::cout << firstName << std::endl;
    std::cout << lastName << std::endl;
    std::cout << Nickname << std::endl;
    std::cout << phone << std::endl;
    std::cout << secret << std::endl;
}

void    Contact::addData()
{
    std::getline(std::cin, firstName);
    std::getline(std::cin, lastName);
    std::getline(std::cin, Nickname);
    std::getline(std::cin, phone);
    std::getline(std::cin, secret);
}

Contact::Contact ()
{
	
}