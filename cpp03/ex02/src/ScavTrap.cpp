/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 12:19:14 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/13 12:32:20 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " construcor called!" << std::endl;    
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " destrucor called!" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (!_hitPoints || !_energyPoints) {
        std::cout << "ClapTrap can't attack, it has no "
        << (!_hitPoints ? "hitPoints" : "energyPoints")
        << std::endl; 
        return ;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void   ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}