/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:25:38 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/22 13:16:23 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "Animal: constructor was called" << std::endl;		
}

Animal::Animal(const Animal& other) : _type(other._type)
{
	std::cout << "Animal: copy constructor was called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal: copy assignment operator called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal: destructor was called" << std::endl;
}

std::string	Animal::getType()	const
{
	return _type;	
}