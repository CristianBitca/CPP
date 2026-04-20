/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:12:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/06 08:07:26 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
    T*  _data;
    size_t    _len;
public:
    // Construct
    Array();
    Array(size_t len);
    Array(const Array& other);
    Array& operator=(const Array& other);
    // Deconstruct
    ~Array();
    // Getter
    size_t  size()    const;
    // Operator []
    T&  operator[](size_t len);
    const T& operator[](size_t len) const;
};

#include "Array.tpp"

#endif