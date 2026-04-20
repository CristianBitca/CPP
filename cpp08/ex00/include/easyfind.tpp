/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:51:16 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/07 08:14:26 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template <typename T>
typename T::iterator  easyfind(T& container, int find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), find);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;  
}

template <typename T>
typename T::const_iterator  easyfind(const T& container, int find)
{
    typename T::iterator it = std::find(container.begin(), container.end(), find);
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }
    return it;
}

#endif