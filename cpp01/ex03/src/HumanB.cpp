/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:49:24 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 20:13:12 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}

HumanB::HumanB(std::string name, Weapon &type) : _name(name), _weapon(&type)
{
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &type)
{
	_weapon = &type;
}

void	HumanB::attack()	const
{
	if (!_weapon) {
		std::cout << _name << " has no weapon!" << std::endl;
		return ;	
	}
	std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}