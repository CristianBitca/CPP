/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:17:34 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/07 08:11:41 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename Container>
void testContainer(Container &container, int searchVal)
{
    try
    {
        typename Container::iterator it = easyfind(container, searchVal);
        std::cout << "Found value " << *it << " in container\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    std::list<int> lst;
    std::deque<int> deq;

    for (int i = 1; i <= 5; ++i)
    {
        vec.push_back(i * 10);  // 10, 20, 30, 40, 50
        lst.push_back(i * 100); // 100, 200, ...
        deq.push_back(i);       // 1, 2, 3, ...
    }

    std::cout << std::endl
              << "Testing vector:" << std::endl;
    std::cout << "    Test 1:" << std::endl
              << "\t";
    testContainer(vec, 30); // found
    std::cout << "    Test 2:" << std::endl
              << "\t";
    testContainer(vec, 99); // not found

    std::cout << std::endl
              << "Testing list:" << std::endl;
    std::cout << "    Test 1:" << std::endl
              << "\t";
    testContainer(lst, 200); // found
    std::cout << "    Test 2:" << std::endl
              << "\t";
    testContainer(lst, 123); // not found

    std::cout << std::endl
              << "Testing deque:" << std::endl;
    std::cout << "    Test 1:" << std::endl
              << "\t";
    testContainer(deq, 3); // found
    std::cout << "    Test 2:" << std::endl
              << "\t";
    testContainer(deq, 0); // not found

    return 0;
}