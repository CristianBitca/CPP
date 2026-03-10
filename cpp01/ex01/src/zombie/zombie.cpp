/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:10:50 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 15:46:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie() : _name("")
{
}

Zombie::~Zombie()
{
	std::cout << _name << ZOMBIE_DECONSTRUC << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce()
{
	std::cout << _name << ANNOUNCE << std::endl;
}