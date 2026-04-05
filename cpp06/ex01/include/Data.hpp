/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 09:13:06 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 09:25:51 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>

struct Data
{
    int Id;
    std::string Name;
    std::string Pass;
    int Phone;
};

void    printData(const Data& data);

#endif