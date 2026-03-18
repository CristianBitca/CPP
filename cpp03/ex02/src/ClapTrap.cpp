/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:35:11 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/13 12:32:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " construcor called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destrucor called!" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
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

void    ClapTrap::beRepaired(unsigned int value)
{
    if (!_hitPoints || !_energyPoints) {
        std::cout << "ClapTrap can't repair itself, it has no "
        << (!_hitPoints ? "hitPoints" : "energyPoints")
        << std::endl; 
        return ;
    }
    _energyPoints--;
    _hitPoints += value;
    std::cout << "ClapTrap " << _name << " was repaired, causing receiving " << value << " points of hit points!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int value)
{
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap can't take any more damage, it's already dead " << std::endl; 
        return ;
    }
    _hitPoints -= value;
    if (_hitPoints < 0)
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name << " was attacked, causing losing " << value << " points of hit points!" << std::endl;
}