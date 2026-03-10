/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:49:26 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 19:11:35 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : _name(name), _weapon(type)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()	const
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}