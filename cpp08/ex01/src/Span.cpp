/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:16:31 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/18 11:41:44 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int maxSize) : _maxSize(maxSize)
{
    _numbers.reserve(maxSize);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span()
{
}

void    Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw std::out_of_range("Span is full");
    }
    _numbers.push_back(number);
}

long    Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Cannot find span with less than 2 numbers");
    }
    std::vector<int> buffer(_numbers); 
    std::sort(buffer.begin(), buffer.end());
    long span = buffer[1] - buffer[0];
    for (size_t i = 0; i < buffer.size() - 1; i++) {
        long tmp = buffer[i + 1] - buffer[i];
        if (tmp < span) {
            span = tmp;
        }  
    }
    return span;
}

long    Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Cannot find span with less than 2 numbers");
    }
    return (*std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end()));
}