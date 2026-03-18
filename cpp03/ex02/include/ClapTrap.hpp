/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 21:34:16 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/13 12:27:21 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string	_name;
	int	_hitPoints;
	int	_energyPoints;
	int	_attackDamage;
public:
	ClapTrap(const std::string& name);
	~ClapTrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned	int	amount);
	void	beRepaired(unsigned int	amount);
};

#endif