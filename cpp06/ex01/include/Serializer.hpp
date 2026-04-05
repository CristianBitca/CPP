/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 09:13:03 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 09:38:58 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
private:
    Serializer();
    ~Serializer();
public:
    static uintptr_t serealize(Data* ptr);
    static Data* deserealize(uintptr_t raw);
};

#endif
