/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 12:43:29 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 12:44:55 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
 
int main()
{
    std::cout << "=== Testing Random Generation and Identification ===" << std::endl;
    std::cout << std::endl;
    
    // Test 1: Generate random instance and identify with pointer
    std::cout << "Test 1: Random generation" << std::endl;
    Base* random = generate();
    std::cout << "Identify by pointer: ";
    identify(random);
    std::cout << "Identify by reference: ";
    identify(*random);
    delete random;
    std::cout << std::endl;
    
    // Test 2: Create specific instances and test both identify functions
    std::cout << "Test 2: Specific type A" << std::endl;
    Base* a = new A();
    std::cout << "Identify by pointer: ";
    identify(a);
    std::cout << "Identify by reference: ";
    identify(*a);
    delete a;
    std::cout << std::endl;
    
    std::cout << "Test 3: Specific type B" << std::endl;
    Base* b = new B();
    std::cout << "Identify by pointer: ";
    identify(b);
    std::cout << "Identify by reference: ";
    identify(*b);
    delete b;
    std::cout << std::endl;
    
    std::cout << "Test 4: Specific type C" << std::endl;
    Base* c = new C();
    std::cout << "Identify by pointer: ";
    identify(c);
    std::cout << "Identify by reference: ";
    identify(*c);
    delete c;
    std::cout << std::endl;
    
    // Test 5: Multiple random generations
    std::cout << "Test 5: Multiple random generations" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "\nRound " << i + 1 << ":" << std::endl;
        Base* obj = generate();
        std::cout << "Identified by pointer: ";
        identify(obj);
        std::cout << "Identified by reference: ";
        identify(*obj);
        delete obj;
    }
    
    return 0;
}