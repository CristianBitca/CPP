/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:12:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 18:37:32 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void    iter(const T* array, size_t len, void (*f)(const T&))
{
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
    }       
}


template <typename T>
void    iter(T* array, size_t len, void (*f)(T&))
{
    for (size_t i = 0; i < len; i++) {
        f(array[i]);
    }
}

#endif