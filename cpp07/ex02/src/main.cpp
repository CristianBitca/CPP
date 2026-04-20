/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:17:34 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/06 08:21:44 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

// ============================================================================
// Helper functions for displaying arrays
// ============================================================================
 
template <typename T>
void    printArray(const Array<T>& arr, const std::string& label)
{
    std::cout << label << ": [";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i];
        if (i < arr.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
 
void    printSeparator()
{
    std::cout << "----------------------------------------" << std::endl;
}
 
// ============================================================================
// Custom class for testing
// ============================================================================
 
class Person
{
public:
    std::string name;
    int age;
    
    Person() : name("Unknown"), age(0) {}
    Person(std::string n, int a) : name(n), age(a) {}
    
    friend std::ostream& operator<<(std::ostream& os, const Person& p)
    {
        os << p.name << "(" << p.age << ")";
        return os;
    }
};
 
// ============================================================================
// Main test function
// ============================================================================
 
int main()
{
    std::cout << "\n=== Testing Array<T> Template Class ===" << std::endl;
    std::cout << std::endl;
    
    // ========================================================================
    // Test 1: Default constructor (empty array)
    // ========================================================================
    std::cout << "Test 1: Default constructor (empty array)" << std::endl;
    printSeparator();
    {
        Array<int> empty;
        std::cout << "Created empty array" << std::endl;
        std::cout << "Size: " << empty.size() << std::endl;
        std::cout << "Expected: 0" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 2: Parameterized constructor with integers
    // ========================================================================
    std::cout << "Test 2: Parameterized constructor - Array<int>(5)" << std::endl;
    printSeparator();
    {
        Array<int> intArray(5);
        std::cout << "Created array of 5 integers" << std::endl;
        std::cout << "Size: " << intArray.size() << std::endl;
        
        std::cout << "Default values: ";
        for (size_t i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;
        std::cout << "Expected: 0 0 0 0 0 (default-initialized)" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 3: Modifying elements with subscript operator
    // ========================================================================
    std::cout << "Test 3: Modifying elements with operator[]" << std::endl;
    printSeparator();
    {
        Array<int> arr(5);
        std::cout << "Before modification: ";
        printArray(arr, "");
        
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        arr[3] = 40;
        arr[4] = 50;
        
        std::cout << "After modification:  ";
        printArray(arr, "");
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 4: Copy constructor - Deep copy test
    // ========================================================================
    std::cout << "Test 4: Copy constructor - Deep copy verification" << std::endl;
    printSeparator();
    {
        Array<int> original(3);
        original[0] = 100;
        original[1] = 200;
        original[2] = 300;
        
        printArray(original, "Original");
        
        Array<int> copy(original);
        printArray(copy, "Copy    ");
        
        std::cout << "\nModifying copy[0] to 999..." << std::endl;
        copy[0] = 999;
        
        printArray(original, "Original");
        printArray(copy, "Copy    ");
        
        if (original[0] == 100 && copy[0] == 999)
            std::cout << "✓ Deep copy works! Arrays are independent." << std::endl;
        else
            std::cout << "✗ Deep copy failed! Arrays are linked." << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 5: Assignment operator - Deep copy test
    // ========================================================================
    std::cout << "Test 5: Assignment operator - Deep copy verification" << std::endl;
    printSeparator();
    {
        Array<int> arr1(3);
        arr1[0] = 10;
        arr1[1] = 20;
        arr1[2] = 30;
        
        Array<int> arr2(2);
        arr2[0] = 99;
        arr2[1] = 88;
        
        printArray(arr1, "arr1 before");
        printArray(arr2, "arr2 before");
        
        std::cout << "\nExecuting: arr2 = arr1" << std::endl;
        arr2 = arr1;
        
        printArray(arr1, "arr1 after ");
        printArray(arr2, "arr2 after ");
        
        std::cout << "\nModifying arr2[0] to 777..." << std::endl;
        arr2[0] = 777;
        
        printArray(arr1, "arr1       ");
        printArray(arr2, "arr2       ");
        
        if (arr1[0] == 10 && arr2[0] == 777)
            std::cout << "✓ Assignment deep copy works!" << std::endl;
        else
            std::cout << "✗ Assignment deep copy failed!" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 6: Self-assignment test
    // ========================================================================
    std::cout << "Test 6: Self-assignment (arr = arr)" << std::endl;
    printSeparator();
    {
        Array<int> arr(3);
        arr[0] = 5;
        arr[1] = 10;
        arr[2] = 15;
        
        printArray(arr, "Before");
        
        arr = arr;  // Self-assignment
        
        printArray(arr, "After ");
        std::cout << "✓ Self-assignment handled correctly" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 7: Exception handling - Out of bounds access
    // ========================================================================
    std::cout << "Test 7: Exception handling - Out of bounds" << std::endl;
    printSeparator();
    {
        Array<int> arr(5);
        
        std::cout << "Array size: " << arr.size() << std::endl;
        std::cout << "Valid indices: 0-4" << std::endl;
        
        // Test 1: Access within bounds
        std::cout << "\nTesting arr[2] (valid): ";
        try {
            arr[2] = 42;
            std::cout << "Success! Value = " << arr[2] << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        
        // Test 2: Access out of bounds (upper)
        std::cout << "Testing arr[10] (invalid): ";
        try {
            arr[10] = 42;
            std::cout << "No exception thrown! ✗" << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "✓ Exception caught: " << e.what() << std::endl;
        }
        
        // Test 3: Access empty array
        Array<int> empty;
        std::cout << "Testing empty[0] (invalid): ";
        try {
            empty[0] = 42;
            std::cout << "No exception thrown! ✗" << std::endl;
        }
        catch (std::exception& e) {
            std::cout << "✓ Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 8: Const correctness - Reading from const array
    // ========================================================================
    std::cout << "Test 8: Const correctness" << std::endl;
    printSeparator();
    {
        Array<int> arr(3);
        arr[0] = 100;
        arr[1] = 200;
        arr[2] = 300;
        
        const Array<int>& constRef = arr;
        
        std::cout << "Reading from const array reference:" << std::endl;
        std::cout << "constRef[0] = " << constRef[0] << std::endl;
        std::cout << "constRef[1] = " << constRef[1] << std::endl;
        std::cout << "constRef[2] = " << constRef[2] << std::endl;
        
        // The following should NOT compile:
        // constRef[0] = 999;  // Error: cannot modify const array
        
        std::cout << "✓ Const version of operator[] works" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 9: Array of strings
    // ========================================================================
    std::cout << "Test 9: Array<std::string>" << std::endl;
    printSeparator();
    {
        Array<std::string> strArray(4);
        std::cout << "Created Array<std::string>(4)" << std::endl;
        std::cout << "Default values: ";
        printArray(strArray, "");
        
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "C++";
        strArray[3] = "Templates";
        
        std::cout << "After assignment: ";
        printArray(strArray, "");
        
        // Copy test
        Array<std::string> copy = strArray;
        copy[0] = "Modified";
        
        printArray(strArray, "Original");
        printArray(copy, "Copy    ");
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 10: Array of doubles
    // ========================================================================
    std::cout << "Test 10: Array<double>" << std::endl;
    printSeparator();
    {
        Array<double> doubleArray(5);
        
        doubleArray[0] = 3.14;
        doubleArray[1] = 2.71;
        doubleArray[2] = 1.41;
        doubleArray[3] = 1.73;
        doubleArray[4] = 2.23;
        
        printArray(doubleArray, "Doubles");
        
        std::cout << "Size: " << doubleArray.size() << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 11: Array of custom class (Person)
    // ========================================================================
    std::cout << "Test 11: Array<Person> (custom class)" << std::endl;
    printSeparator();
    {
        Array<Person> people(3);
        
        std::cout << "Default-initialized people:" << std::endl;
        printArray(people, "");
        
        people[0] = Person("Alice", 25);
        people[1] = Person("Bob", 30);
        people[2] = Person("Charlie", 35);
        
        std::cout << "\nAfter assignment:" << std::endl;
        printArray(people, "");
        
        // Deep copy test
        Array<Person> peopleCopy = people;
        peopleCopy[0] = Person("Modified", 99);
        
        std::cout << "\nAfter copying and modifying copy:" << std::endl;
        printArray(people, "Original");
        printArray(peopleCopy, "Copy    ");
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 12: Large array test
    // ========================================================================
    std::cout << "Test 12: Large array (1000 elements)" << std::endl;
    printSeparator();
    {
        Array<int> large(1000);
        std::cout << "Created array of size: " << large.size() << std::endl;
        
        // Fill with values
        for (size_t i = 0; i < large.size(); i++)
            large[i] = i * 2;
        
        std::cout << "First 10 elements: ";
        for (size_t i = 0; i < 10; i++)
            std::cout << large[i] << " ";
        std::cout << std::endl;
        
        std::cout << "Last 10 elements: ";
        for (size_t i = large.size() - 10; i < large.size(); i++)
            std::cout << large[i] << " ";
        std::cout << std::endl;
        
        std::cout << "✓ Large array handled successfully" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 13: Multiple assignments chain
    // ========================================================================
    std::cout << "Test 13: Chained assignments (a = b = c)" << std::endl;
    printSeparator();
    {
        Array<int> a(2);
        Array<int> b(2);
        Array<int> c(2);
        
        c[0] = 100;
        c[1] = 200;
        
        a = b = c;  // Chained assignment
        
        printArray(a, "a");
        printArray(b, "b");
        printArray(c, "c");
        
        std::cout << "✓ Chained assignment works" << std::endl;
    }
    std::cout << std::endl;
    
    // ========================================================================
    // Test 14: Size variations
    // ========================================================================
    std::cout << "Test 14: Various sizes" << std::endl;
    printSeparator();
    {
        Array<int> arr0(0);
        Array<int> arr1(1);
        Array<int> arr10(10);
        Array<int> arr100(100);
        
        std::cout << "Array(0) size: " << arr0.size() << std::endl;
        std::cout << "Array(1) size: " << arr1.size() << std::endl;
        std::cout << "Array(10) size: " << arr10.size() << std::endl;
        std::cout << "Array(100) size: " << arr100.size() << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "=== All tests completed ===" << std::endl;
    std::cout << std::endl;
    
    return 0;
}
