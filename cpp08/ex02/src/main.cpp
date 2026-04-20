/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 10:53:46 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/20 11:31:09 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    std::cout << "=== Test 1: Subject Example ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        
        ++it;
        --it;
        
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n=== Test 2: Compare with std::list ===" << std::endl;
    {
        // Same operations but with std::list to show similarity
        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(17);
        std::cout << lst.back() << std::endl;
        lst.pop_back();
        std::cout << lst.size() << std::endl;
        lst.push_back(3);
        lst.push_back(5);
        lst.push_back(737);
        lst.push_back(0);
        
        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();
        
        ++it;
        --it;
        
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << "\n=== Test 3: Const Iterator ===" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        
        const MutantStack<int> const_stack(mstack);
        
        MutantStack<int>::const_iterator cit = const_stack.begin();
        MutantStack<int>::const_iterator cite = const_stack.end();
        
        std::cout << "Const iteration: ";
        while (cit != cite)
        {
            std::cout << *cit << " ";
            ++cit;
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 4: Copy Constructor & Assignment ===" << std::endl;
    {
        MutantStack<int> mstack1;
        mstack1.push(42);
        mstack1.push(84);
        
        MutantStack<int> mstack2(mstack1);  // Copy constructor
        MutantStack<int> mstack3;
        mstack3 = mstack1;  // Assignment operator
        
        std::cout << "Original top: " << mstack1.top() << std::endl;
        std::cout << "Copied top: " << mstack2.top() << std::endl;
        std::cout << "Assigned top: " << mstack3.top() << std::endl;
    }

    std::cout << "\n=== Test 5: Different Types ===" << std::endl;
    {
        MutantStack<std::string> str_stack;
        str_stack.push("Hello");
        str_stack.push("World");
        str_stack.push("!");
        
        for (MutantStack<std::string>::iterator it = str_stack.begin(); 
             it != str_stack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\n=== Test 6: Empty Stack ===" << std::endl;
    {
        MutantStack<int> empty;
        
        std::cout << "Empty: " << empty.empty() << std::endl;
        std::cout << "Size: " << empty.size() << std::endl;
        
        // Iterating empty stack should do nothing
        MutantStack<int>::iterator it = empty.begin();
        MutantStack<int>::iterator ite = empty.end();
        
        int count = 0;
        while (it != ite) {
            ++count;
            ++it;
        }
        std::cout << "Iterations on empty: " << count << std::endl;
    }

    std::cout << "\n=== All Tests Complete! ===" << std::endl;
    return 0;
}