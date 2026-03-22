/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:10:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/22 12:51:01 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

static void printSeparator(const std::string& title)
{
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
    // -----------------------------------------------
    // TEST 1: Subject required test
    // -----------------------------------------------
    printSeparator("Subject Required Test");

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    j->makeSound();
    i->makeSound();

    delete j;  // must call ~Dog() which deletes Brain
    delete i;  // must call ~Cat() which deletes Brain

    // -----------------------------------------------
    // TEST 2: Array of Animals — half Dog half Cat
    // -----------------------------------------------
    printSeparator("Animal Array Test");

    const Animal* zoo[10];
    for (int idx = 0; idx < 5; idx++)
        zoo[idx] = new Dog();
    for (int idx = 5; idx < 10; idx++)
        zoo[idx] = new Cat();

    for (int idx = 0; idx < 10; idx++)
        zoo[idx]->makeSound();

    for (int idx = 0; idx < 10; idx++)
        delete zoo[idx];  // each delete must free its Brain too

    // -----------------------------------------------
    // TEST 3: Deep copy Dog — brains must be independent
    // -----------------------------------------------
    printSeparator("Deep Copy Dog Test");

    Dog dogA;
    Dog dogB(dogA);  // copy constructor

    // if shallow copy: both point to same Brain — crash on delete
    // if deep copy: each has its own Brain — safe

    std::cout << "dogA type: " << dogA.getType() << std::endl;
    std::cout << "dogB type: " << dogB.getType() << std::endl;
    dogA.makeSound();
    dogB.makeSound();

    // -----------------------------------------------
    // TEST 4: Deep copy Cat — assignment operator
    // -----------------------------------------------
    printSeparator("Deep Copy Cat Test");

    Cat catA;
    Cat catB;
    catB = catA;  // assignment operator

    std::cout << "catA type: " << catA.getType() << std::endl;
    std::cout << "catB type: " << catB.getType() << std::endl;
    catA.makeSound();
    catB.makeSound();

    // -----------------------------------------------
    // TEST 5: Deep copy proof — different Brain addresses
    // -----------------------------------------------
    printSeparator("Brain Address Test");

    Dog dogC;
    Dog dogD(dogC);

    std::cout << "dogC brain address: " << dogC.getBrain() << std::endl;
    std::cout << "dogD brain address: " << dogD.getBrain() << std::endl;
    // addresses must be DIFFERENT — proves deep copy worked

    return 0;
}