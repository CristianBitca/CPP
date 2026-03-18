/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 13:42:52 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/13 12:31:01 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "=== Creating ClapTrap ===" << std::endl;
    ClapTrap ct("Clappy");

    std::cout << "\n=== Normal attack ===" << std::endl;
    ct.attack("Enemy");

    std::cout << "\n=== Taking damage ===" << std::endl;
    ct.takeDamage(5);

    std::cout << "\n=== Repairing ===" << std::endl;
    ct.beRepaired(3);

    std::cout << "\n=== Draining all energy (10 attacks) ===" << std::endl;
    for (int i = 0; i < 9; i++)
        ct.attack("Enemy");

    std::cout << "\n=== Attack with no energy ===" << std::endl;
    ct.attack("Enemy");

    std::cout << "\n=== Repair with no energy ===" << std::endl;
    ct.beRepaired(5);

    std::cout << "\n=== Taking lethal damage ===" << std::endl;
    ct.takeDamage(100);

    std::cout << "\n=== Attack when dead ===" << std::endl;
    ct.attack("Enemy");

    std::cout << "\n=== Take damage when already dead ===" << std::endl;
    ct.takeDamage(5);

    std::cout << "\n=== Destroying ClapTrap ===" << std::endl;

    std::cout << "\n=== ScavTrap tests ===" << std::endl;
    ScavTrap sc("Scavvy");

    sc.guardGate();
    sc.attack("Enemy");
    sc.takeDamage(50);
    sc.beRepaired(20);

    std::cout << "\n=== Chaining proof (watch constructor/destructor order) ===" << std::endl;
    {
        ScavTrap temp("Temp");
    }
    return 0;
}