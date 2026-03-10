/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:00:15 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 15:46:35 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
	Zombie* horde = new Zombie[n];

	for (int i = 0; i < n; i++)
		horde[i].setName(name);
	return (&horde[0]);
}