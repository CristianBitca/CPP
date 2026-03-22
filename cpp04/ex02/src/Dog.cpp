/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:30:42 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/22 12:55:25 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    _brain = new Brain();
	std::cout << "Dog: constructor was called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	_brain = new Brain(*other._brain);
	std::cout << "Dog: copy constructor was called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Dog: copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain; 
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog: destructor was called" << std::endl;
	delete _brain;
}

void	Dog::makeSound()	const
{
	std::cout << "Dog: Woof! Woof!" << std::endl;
}

Brain*  Dog::getBrain() const
{
	return _brain;
}