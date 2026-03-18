/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 13:11:53 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/13 13:22:18 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " construcor called!" << std::endl;    
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destrucor called!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (!_hitPoints || !_energyPoints) {
        std::cout << "FragTrap " << _name << " can't attack, no "
                  << (!_hitPoints ? "hit points" : "energy points") << "!" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " blasts " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void   FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " requests a high five! Anyone? ✋" << std::endl;
}