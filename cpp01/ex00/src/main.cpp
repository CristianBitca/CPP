/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:10:41 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 15:19:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

int	main()
{
    // Heap zombie: lives beyond the call, we control when it dies
    std::cout << "--- Heap zombie (newZombie) ---" << std::endl;
    Zombie* heapZombie = newZombie( "HeapGroan" );
    heapZombie->announce();

    // Stack zombie: created and destroyed inside randomChump
    std::cout << "\n--- Stack zombie (randomChump) ---" << std::endl;
    randomchump( "StackRot" );

    // Heap zombie destroyed here - we choose when
    std::cout << "\n--- Deleting heap zombie ---" << std::endl;
    delete heapZombie;

    return 0;
}