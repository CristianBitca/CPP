/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:24:00 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/11 17:21:27 by cbitca           ###   ########.fr       */
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

Fixed::Fixed(const int raw) : _rawBits(raw << _fractionalBits)
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

bool Fixed::operator>(const Fixed &other)	const
{
	return (_rawBits > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other)	const
{
	return (_rawBits < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other)	const
{
	return (_rawBits >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other)	const
{
	return (_rawBits <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other)	const
{
	return (_rawBits == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other)	const
{
	return (_rawBits != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed &other)	const
{
	return Fixed(toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other)	const
{
	return Fixed(toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other)	const
{
	return Fixed(toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other)	const
{
	return Fixed(toFloat() / other.toFloat());
}

Fixed	Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	_rawBits++;
	return tmp;
}

Fixed	Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	_rawBits--;
	return tmp;
}

Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	return (one <= two ? one : two);
}

const Fixed&	Fixed::min(const Fixed& one, const Fixed& two)
{
	return (one <= two ? one : two);
}

Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	return (one >= two ? one : two);
}

const Fixed&	Fixed::max(const Fixed& one, const Fixed& two)
{
	return (one >= two ? one : two);
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

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}