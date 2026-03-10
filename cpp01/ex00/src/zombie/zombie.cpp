/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:10:50 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 15:19:10 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(std::string name) : _name(name)
{
}

Zombie::~Zombie()
{
	std::cout << _name << ZOMBIE_DECONSTRUC << std::endl;
}

void	Zombie::announce()
{
	std::cout << _name << ANNOUNCE << std::endl;
}