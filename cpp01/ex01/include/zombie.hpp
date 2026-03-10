/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:10:37 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 16:08:05 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

#define	ZOMBIE_DECONSTRUC	" desconstruct call"
#define ANNOUNCE			": BraiiiiiiinnnzzzZ..."

class Zombie
{
private:
	std::string	_name;
public:
	Zombie();
	~Zombie();
	void	announce();
	void	setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);

#endif