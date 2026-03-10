/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:10:41 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 15:47:18 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main()
{
    int n = 5;

    std::cout << "--- Zombie Horde ---" << std::endl;
    Zombie* horde = zombieHorde(n, "Bob");

    for (int i = 0; i < n; i++)
        horde[i].announce();

    std::cout << "\n--- Deleting horde ---" << std::endl;
    delete[] horde;

    return 0;
}