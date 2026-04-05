/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 09:12:57 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 09:39:26 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    
}

Serializer::~Serializer()
{
    
}

uintptr_t Serializer::serealize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserealize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
