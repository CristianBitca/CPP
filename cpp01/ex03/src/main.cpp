/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:49:22 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 20:13:27 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
    std::cout << "--- HumanA (always has a weapon) ---" << std::endl;
    {
		Weapon	club("Spike club");
		HumanA	bob("Bob", club);

		bob.attack();
		club.setType("AK 47");
		bob.attack();
    }

    std::cout << "\n--- HumanB (weapon assigned later) ---" << std::endl;
    {
		Weapon	club("Spike club");
		HumanB	frank("Frank");

		frank.attack();
		frank.setWeapon(club);
		frank.attack();
		club.setType("AK 47");
		frank.attack();
    }
    return 0;
}