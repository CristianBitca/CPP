/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:34:16 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/11 21:42:20 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string	_name;
	int	_heal = 10;
	int	_energy = 10;
	int	_attack = 0;
public:
	ClapTrap(std::string name);
	~ClapTrap();
	void	setHeal(int value);
	void	setEnergy(int value);
	void	setAttack(int value);
	void	attack(const std::string& target);
	void	takeDamage(unsigned	int	amount);
	void	beRepaired(unsigned int	amount);
};

#endif