/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:08:59 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/17 20:09:54 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat: constructor was called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "WrongCat: copy constructor was called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat: copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: destructor was called" << std::endl;
}

void	WrongCat::makeSound()	const
{
	std::cout << "WrongCat: Meow! Purrrr..." << std::endl;
}
