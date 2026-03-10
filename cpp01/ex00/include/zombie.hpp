/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:10:37 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 15:18:29 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#define	ZOMBIE_DECONSTRUC	" desconstruct call"
#define ANNOUNCE			": BraiiiiiiinnnzzzZ..."

class Zombie
{
private:
	std::string	_name;
public:
	Zombie(std::string name);
	~Zombie();
	void	announce();
};

Zombie* newZombie( std::string name );
void    randomchump( std::string name );

#endif