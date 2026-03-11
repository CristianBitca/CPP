/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 12:37:35 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/11 14:01:06 by cbitca           ###   ########.fr       */
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
	int	getRawBits()	const;
	void	setRawBits(int const raw);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

#endif