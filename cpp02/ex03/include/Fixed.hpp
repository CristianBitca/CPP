/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:22:39 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/11 17:12:30 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_rawBits;
	static const int _fractionalBits = 8;
public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed(const int raw);
	Fixed(const float raw);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	float	toFloat()	const;
	int	toInt()	const;
	bool operator>(const Fixed &other)	const;
	bool operator<(const Fixed &other)	const;
	bool operator>=(const Fixed &other)	const;
	bool operator<=(const Fixed &other)	const;
	bool operator==(const Fixed &other)	const;
	bool operator!=(const Fixed &other)	const;
	Fixed	operator+(const Fixed &other)	const;
	Fixed	operator-(const Fixed &other)	const;
	Fixed	operator*(const Fixed &other)	const;
	Fixed	operator/(const Fixed &other)	const;
	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);
	static	Fixed&	min(Fixed& one, Fixed& two);
	static const	Fixed&	min(const Fixed& one, const Fixed& two);
	static	Fixed&	max(Fixed& one, Fixed& two);
	static const	Fixed&	max(const Fixed& one, const Fixed& two);
	int	getRawBits()	const;
	void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif