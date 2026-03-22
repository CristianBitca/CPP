/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 19:18:28 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/22 12:55:52 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	_brain = new Brain;
	std::cout << "Cat: constructor was called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat: copy constructor was called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat: copy assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (_brain)
			delete _brain; 
		_brain = new Brain(*other._brain);
	}	
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat: destructor was called" << std::endl;
	delete _brain;
}

void	Cat::makeSound()	const
{
	std::cout << "Cat: Meow! Purrrr..." << std::endl;
}

Brain*  Cat::getBrain() const
{
	return _brain;
}
