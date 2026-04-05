/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 09:12:54 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 09:45:04 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data* origin = new Data;
    origin->Id = 1;
    origin->Name = "cbitca";
    origin->Pass = "pass";
    origin->Phone = 42;

    std::cout << "Original data:\n";
	printData(*origin);
	std::cout << "Address of original: " << origin << std::endl;

	uintptr_t raw = Serializer::serealize(origin);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	Data* deserialized = Serializer::deserealize(raw);
	std::cout << "\nDeserialized data:\n";
	printData(*deserialized);
	std::cout << "Address of deserialized: " << deserialized << std::endl;

	if (origin == deserialized)
		std::cout << "\n Success: Pointers match!" << std::endl;
	else
		std::cout << "\n Error: Pointers do not match!" << std::endl;

	delete origin;

    return 0;
}