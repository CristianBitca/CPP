/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 11:16:34 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/18 11:40:56 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int>    _numbers; 
public:
    Span(unsigned int maxSize);
    Span(const Span& other);
    Span&   operator=(const Span& other);
    ~Span();

    void    addNumber(int number);
    long    shortestSpan()  const;
    long    longestSpan()   const;
    template<typename Iterator>
    void    addRange(Iterator begin, Iterator end) {
        for (Iterator it = begin; it != end; ++it)
            addNumber(*it);
    }
};

#endif