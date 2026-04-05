/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 09:13:00 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 09:30:34 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

void    printData(const Data& data)
{
    std::cout << "Id: " << data.Id
        << " Name: " << data.Name
        << " Pass: " << data.Pass
        << " Phone: " << data.Phone
        << std::endl;
}