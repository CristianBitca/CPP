/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:10:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/17 20:14:42 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

    const Animal* meta = new Animal();
    const Animal* j    = new Dog();
    const Animal* i    = new Cat();

    std::cout << j->getType() << std::endl; // Dog
    std::cout << i->getType() << std::endl; // Cat
    i->makeSound();    // Cat sound via Animal pointer
    j->makeSound();    // Dog sound via Animal pointer
    meta->makeSound(); // Generic Animal sound

    delete meta;
    delete j;
    delete i;

    // -----------------------------------------------
    // TEST 2: Polymorphism array
    // -----------------------------------------------
    printSeparator("Polymorphism Array Test");

    const Animal* zoo[4];
    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Dog();
    zoo[3] = new Cat();

    for (int idx = 0; idx < 4; idx++)
    {
        std::cout << zoo[idx]->getType() << " says: ";
        zoo[idx]->makeSound();
    }
    for (int idx = 0; idx < 4; idx++)
        delete zoo[idx];

    // -----------------------------------------------
    // TEST 3: Stack objects — destructor order
    // -----------------------------------------------
    printSeparator("Stack Objects Test");
    {
        Animal  a;
        Dog     d;
        Cat     c;

        a.makeSound();
        d.makeSound();
        c.makeSound();
    } // destructors fire here in reverse order: ~Cat ~Dog ~Animal

    // -----------------------------------------------
    // TEST 4: Copy constructor
    // -----------------------------------------------
    printSeparator("Copy Constructor Test");

    Dog original;
    Dog copy(original);

    std::cout << "original type: " << original.getType() << std::endl;
    std::cout << "copy type:     " << copy.getType() << std::endl;
    original.makeSound();
    copy.makeSound();

    // -----------------------------------------------
    // TEST 5: Assignment operator
    // -----------------------------------------------
    printSeparator("Assignment Operator Test");

    Cat catA;
    Cat catB;
    catB = catA;

    std::cout << "catA type: " << catA.getType() << std::endl;
    std::cout << "catB type: " << catB.getType() << std::endl;
    catA.makeSound();
    catB.makeSound();

    // -----------------------------------------------
    // TEST 6: WrongAnimal / WrongCat — no polymorphism
    // -----------------------------------------------
    printSeparator("WrongAnimal / WrongCat Test");

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat  = new WrongCat();

    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();   // prints WrongAnimal sound — NOT WrongCat ❌
    wrongMeta->makeSound();  // prints WrongAnimal sound

    delete wrongMeta;
    delete wrongCat;

    return 0;
}