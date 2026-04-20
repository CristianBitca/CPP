/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:17:34 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 18:38:26 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>
 
// ============================================================================
// Test functions for integers
// ============================================================================
 
void    printInt(const int& n)
{
    std::cout << n << " ";
}
 
void    incrementInt(int& n)
{
    n++;
}
 
void    doubleInt(int& n)
{
    n *= 2;
}
 
// ============================================================================
// Test functions for strings
// ============================================================================
 
void    printString(const std::string& s)
{
    std::cout << "\"" << s << "\" ";
}
 
void    toUpperCase(std::string& s)
{
    for (size_t i = 0; i < s.length(); i++)
        s[i] = std::toupper(s[i]);
}
 
// ============================================================================
// Test functions for doubles
// ============================================================================
 
void    printDouble(const double& d)
{
    std::cout << d << " ";
}
 
void    squareDouble(double& d)
{
    d = d * d;
}
 
// ============================================================================
// Test functions for chars
// ============================================================================
 
void    printChar(const char& c)
{
    std::cout << c;
}
 
void    shiftChar(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;  // Convert to uppercase
}
 
// ============================================================================
// Custom class for testing
// ============================================================================
 
class Person
{
public:
    std::string name;
    int age;
    
    Person(std::string n, int a) : name(n), age(a) {}
};
 
void    printPerson(const Person& p)
{
    std::cout << p.name << " (" << p.age << ") ";
}
 
void    agePerson(Person& p)
{
    p.age++;
}
 
// ============================================================================
// Main test function
// ============================================================================
 
int main()
{
    std::cout << "=== Testing iter() template function ===" << std::endl;
    std::cout << std::endl;
    
    // ========================================================================
    // Test 1: Integer array - const operation
    // ========================================================================
    std::cout << "Test 1: Integer array - printing (const)" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 2: Integer array - non-const operation
    // ========================================================================
    std::cout << "\nTest 2: Integer array - incrementing (non-const)" << std::endl;
    std::cout << "Before increment: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    iter(intArray, intLen, incrementInt);
    std::cout << "After increment: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 3: Integer array - double values
    // ========================================================================
    std::cout << "\nTest 3: Integer array - doubling values" << std::endl;
    std::cout << "Before doubling: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    iter(intArray, intLen, doubleInt);
    std::cout << "After doubling: ";
    iter(intArray, intLen, printInt);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 4: String array
    // ========================================================================
    std::cout << "\nTest 4: String array" << std::endl;
    std::string strArray[] = {"hello", "world", "c++", "templates"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);
    
    std::cout << "Original: ";
    iter(strArray, strLen, printString);
    std::cout << std::endl;
    
    iter(strArray, strLen, toUpperCase);
    std::cout << "Uppercase: ";
    iter(strArray, strLen, printString);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 5: Double array
    // ========================================================================
    std::cout << "\nTest 5: Double array" << std::endl;
    double doubleArray[] = {1.5, 2.5, 3.5, 4.5};
    size_t doubleLen = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Original: ";
    iter(doubleArray, doubleLen, printDouble);
    std::cout << std::endl;
    
    iter(doubleArray, doubleLen, squareDouble);
    std::cout << "Squared: ";
    iter(doubleArray, doubleLen, printDouble);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 6: Char array
    // ========================================================================
    std::cout << "\nTest 6: Char array" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charLen = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Original: ";
    iter(charArray, charLen, printChar);
    std::cout << std::endl;
    
    iter(charArray, charLen, shiftChar);
    std::cout << "Uppercase: ";
    iter(charArray, charLen, printChar);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 7: Custom class array
    // ========================================================================
    std::cout << "\nTest 7: Custom class (Person) array" << std::endl;
    Person people[] = {
        Person("Alice", 25),
        Person("Bob", 30),
        Person("Charlie", 35)
    };
    size_t peopleLen = sizeof(people) / sizeof(people[0]);
    
    std::cout << "Original: ";
    iter(people, peopleLen, printPerson);
    std::cout << std::endl;
    
    iter(people, peopleLen, agePerson);
    std::cout << "After aging: ";
    iter(people, peopleLen, printPerson);
    std::cout << std::endl;
    
    // ========================================================================
    // Test 8: Empty array edge case
    // ========================================================================
    std::cout << "\nTest 8: Empty array edge case" << std::endl;
    int emptyArray[] = {};
    std::cout << "Calling iter on empty array: ";
    iter(emptyArray, 0, printInt);
    std::cout << "(no output expected)" << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}