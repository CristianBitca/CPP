/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:17:34 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/18 11:45:01 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
    std::cout << "=== Test 1: Basic Example from Subject ===" << std::endl;
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 2: Exception - Span Full ===" << std::endl;
    {
        try {
            Span sp(3);
            sp.addNumber(1);
            sp.addNumber(2);
            sp.addNumber(3);
            sp.addNumber(4);
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Test 3: Exception - Not Enough Numbers ===" << std::endl;
    {
        try {
            Span sp(5);
            sp.addNumber(42);
            std::cout << sp.shortestSpan() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n=== Test 4: Negative Numbers ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(-10);
        sp.addNumber(-5);
        sp.addNumber(0);
        sp.addNumber(5);
        sp.addNumber(10);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 5: Duplicates ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(5);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(15);
        sp.addNumber(100);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 6: Using addRange with 10,000 Numbers ===" << std::endl;
    {
        Span sp(10000);
        std::vector<int> numbers;
        
        srand(time(NULL));
        for (int i = 0; i < 10000; ++i) {
            numbers.push_back(rand() % 100000);
        }
        
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Added 10,000 numbers using iterators" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 7: Using addRange with 100,000 Numbers ===" << std::endl;
    {
        Span sp(100000);
        std::vector<int> numbers;
        
        for (int i = 0; i < 100000; ++i) {
            numbers.push_back(i * 2);
        }
        
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Added 100,000 numbers using iterators" << std::endl;
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 8: Edge Case - Only 2 Numbers ===" << std::endl;
    {
        Span sp(2);
        sp.addNumber(100);
        sp.addNumber(200);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 9: Large Range Values ===" << std::endl;
    {
        Span sp(5);
        sp.addNumber(-2147483648);  // INT_MIN
        sp.addNumber(-1000000);
        sp.addNumber(0);
        sp.addNumber(1000000);
        sp.addNumber(2147483647);   // INT_MAX
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
    }

    std::cout << "\n=== Test 10: Copy Constructor ===" << std::endl;
    {
        Span sp1(5);
        sp1.addNumber(1);
        sp1.addNumber(2);
        sp1.addNumber(3);
        
        Span sp2(sp1);  // Copy constructor
        
        std::cout << "Original shortest span: " << sp1.shortestSpan() << std::endl;
        std::cout << "Copied shortest span: " << sp2.shortestSpan() << std::endl;
    }

    std::cout << "\n=== All Tests Complete! ===" << std::endl;
    return 0;
}