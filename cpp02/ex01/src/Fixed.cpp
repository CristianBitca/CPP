/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:37:38 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/11 13:51:50 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int raw) : _rawBits(raw)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float raw) : _rawBits(roundf(raw * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		_rawBits = other.getRawBits();
	std::cout << "Copy assigment operator called" << std::endl;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt()	const
{
	return _rawBits >> 8;
}

float	Fixed::toFloat()	const
{
	return (float)_rawBits / 256;
}

int	Fixed::getRawBits()	const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _rawBits;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_rawBits = raw;
}