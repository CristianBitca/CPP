/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 20:57:58 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/06 08:08:47 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(0), _len(0)
{
}

template <typename T>
Array<T>::Array(size_t len) : _data(new T[len]), _len(len)
{
}

template <typename T>
Array<T>::Array(const Array& other) : _data(new T[other._len]), _len(other._len)
{
    for (size_t i = 0; i < _len; i++)
        _data[i] = other._data[i];
}

template <typename T>
Array<T>&   Array<T>::operator=(const Array<T>& other)
{
    if (this != &other) {
        delete[] _data;
        _data = new T[other._len];
        _len = other._len;
        for (size_t i = 0; i < _len; i++)
            _data[i] = other._data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    if (!_data)
        delete[] _data;
}

template <typename T>
size_t  Array<T>::size()  const
{
    return _len;
}

template <typename T>
T& Array<T>::operator[](size_t index)
{
    if (index >= _len)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
};

template <typename T>
const T& Array<T>::operator[](size_t index) const
{
    if (index >= _len)
        throw std::out_of_range("Index out of bounds");
    return _data[index];
};

#endif