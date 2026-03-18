/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 17:30:19 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/18 16:39:34 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "utils.hpp"
#include <string>

int     checkPhone(std::string const input)
{
    int i = 0;

	if (input[0] == '+')
        i++;
    do {
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