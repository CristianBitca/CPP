/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:30:42 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/17 19:31:44 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog: constructor was called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog: copy constructor was called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor was called" << std::endl;
}

void	Dog::makeSound()	const
{
	std::cout << "Dog: Woof! Woof!" << std::endl;
}