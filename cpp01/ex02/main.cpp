/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:03:50 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 17:14:49 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *strPTR = &brain;
	std::string &strREF = brain;

	std::cout << "--- Memory Addresses ---" << std::endl;
    std::cout << "brain     address: " << &brain     << std::endl;
    std::cout << "stringPTR holds :  " << strPTR  << std::endl;
    std::cout << "stringREF address: " << &strREF << std::endl;

    std::cout << "\n--- Values --- " << std::endl;
    std::cout << "brain     value: " << brain      << std::endl;
    std::cout << "stringPTR value: " << *strPTR << std::endl;
    std::cout << "stringREF value: " << strREF  << std::endl;
}