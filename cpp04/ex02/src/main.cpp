/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 20:10:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/22 13:17:37 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
 
int main()
{
    // ─────────────────────────────────────────
    // 1. Abstract class cannot be instantiated
    //    Uncomment the line below to confirm it
    //    causes a compile error:
    // ─────────────────────────────────────────
    // Animal a; // error: cannot instantiate abstract class
 
    std::cout << "─── Basic instantiation ───" << std::endl;
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
 
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;
 
    std::cout << std::endl;
 
    // ─────────────────────────────────────────
    // 2. Polymorphic makeSound via base pointer
    // ─────────────────────────────────────────
    std::cout << "─── Polymorphic makeSound ───" << std::endl;
    dog->makeSound();
    cat->makeSound();
 
    std::cout << std::endl;
 
    // ─────────────────────────────────────────
    // 3. Deep copy — Dog
    // ─────────────────────────────────────────
    std::cout << "─── Deep copy (Dog) ───" << std::endl;
    Dog d1;
    d1.getBrain()->setIdea(0, "I love walks");
    Dog d2(d1);                                      // copy constructor
    Dog d3;
    d3 = d1;                                         // assignment operator
 
    std::cout << "d1 idea[0]: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2.getBrain()->getIdea(0) << std::endl;
    std::cout << "d3 idea[0]: " << d3.getBrain()->getIdea(0) << std::endl;
 
    // Modify d1 — d2 and d3 must NOT change (deep copy check)
    d1.getBrain()->setIdea(0, "I changed my mind");
    std::cout << "After modifying d1:" << std::endl;
    std::cout << "d1 idea[0]: " << d1.getBrain()->getIdea(0) << std::endl;
    std::cout << "d2 idea[0]: " << d2.getBrain()->getIdea(0) << std::endl;
    std::cout << "d3 idea[0]: " << d3.getBrain()->getIdea(0) << std::endl;
 
    std::cout << std::endl;
 
    // ─────────────────────────────────────────
    // 4. Deep copy — Cat
    // ─────────────────────────────────────────
    std::cout << "─── Deep copy (Cat) ───" << std::endl;
    Cat c1;
    c1.getBrain()->setIdea(0, "I own this house");
    Cat c2(c1);
 
    std::cout << "c1 idea[0]: " << c1.getBrain()->getIdea(0) << std::endl;
    std::cout << "c2 idea[0]: " << c2.getBrain()->getIdea(0) << std::endl;
 
    c1.getBrain()->setIdea(0, "Now I changed it");
    std::cout << "After modifying c1:" << std::endl;
    std::cout << "c1 idea[0]: " << c1.getBrain()->getIdea(0) << std::endl;
    std::cout << "c2 idea[0]: " << c2.getBrain()->getIdea(0) << std::endl;
 
    std::cout << std::endl;
 
    // ─────────────────────────────────────────
    // 5. Array of Animal* — destructor chain
    // ─────────────────────────────────────────
    std::cout << "─── Array of Animal* (destructor check) ───" << std::endl;
    const int SIZE = 4;
    Animal* animals[SIZE];
 
    for (int i = 0; i < SIZE / 2; i++)
        animals[i] = new Dog();
    for (int i = SIZE / 2; i < SIZE; i++)
        animals[i] = new Cat();
 
    for (int i = 0; i < SIZE; i++)
        animals[i]->makeSound();
 
    std::cout << std::endl;
    std::cout << "─── Deleting array (watch destructors) ───" << std::endl;
    for (int i = 0; i < SIZE; i++)
        delete animals[i];
 
    std::cout << std::endl;
 
    // ─────────────────────────────────────────
    // 6. Clean up heap objects from step 1
    // ─────────────────────────────────────────
    std::cout << "─── Deleting base pointers ───" << std::endl;
    delete dog;
    delete cat;
 
    return 0;
}