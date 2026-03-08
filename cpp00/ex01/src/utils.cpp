/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:30:19 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/08 21:55:46 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <string>

int     checkPhone(std::string const input)
{
    int i = 0;
    do {
        if (input[0] == '+')
            i++;
        if (isdigit(input[i]))
            i++;
        else
            return EXIT_FAILURE;
    }   while (input[i]);
    return EXIT_SUCCESS;
}

void    parseInput(std::string *input)
{
    if (!std::getline(std::cin, *input)) {
		std::cout << std::endl;
		exit(1);	
	}
}