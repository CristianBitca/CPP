/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:16:48 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/25 14:58:48 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
 
// Helper to print section headers
static void section(const std::string& title)
{
    std::cout << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << "==============================" << std::endl;
}
 
int main()
{
    // ------------------------------------------------------------------ //
    //  1. Bureaucrat — valid construction                                 //
    // ------------------------------------------------------------------ //
    section("1. Bureaucrat valid construction");
    {
        Bureaucrat alice("Alice", 1);
        Bureaucrat bob("Bob", 150);
        Bureaucrat mid("Mid", 75);
        std::cout << alice << std::endl;
        std::cout << bob   << std::endl;
        std::cout << mid   << std::endl;
    }
 
    // ------------------------------------------------------------------ //
    //  2. Bureaucrat — grade too high (grade < 1)                        //
    // ------------------------------------------------------------------ //
    section("2. Bureaucrat grade too high exception");
    {
        try {
            Bureaucrat tooHigh("TooHigh", 0);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  3. Bureaucrat — grade too low (grade > 150)                       //
    // ------------------------------------------------------------------ //
    section("3. Bureaucrat grade too low exception");
    {
        try {
            Bureaucrat tooLow("TooLow", 151);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  4. Bureaucrat — increment / decrement normal                      //
    // ------------------------------------------------------------------ //
    section("4. Bureaucrat increment / decrement");
    {
        Bureaucrat b("Charlie", 50);
        std::cout << "Before: " << b << std::endl;
        b.incrementGrade();
        std::cout << "After increment: " << b << std::endl;
        b.decrementGrade();
        b.decrementGrade();
        std::cout << "After 2x decrement: " << b << std::endl;
    }
 
    // ------------------------------------------------------------------ //
    //  5. Bureaucrat — increment past max (grade 1)                      //
    // ------------------------------------------------------------------ //
    section("5. Bureaucrat increment past max");
    {
        Bureaucrat top("Top", 1);
        try {
            top.incrementGrade();
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  6. Bureaucrat — decrement past min (grade 150)                    //
    // ------------------------------------------------------------------ //
    section("6. Bureaucrat decrement past min");
    {
        Bureaucrat bottom("Bottom", 150);
        try {
            bottom.decrementGrade();
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  7. Bureaucrat — copy constructor & assignment                     //
    // ------------------------------------------------------------------ //
    section("7. Bureaucrat copy constructor & assignment");
    {
        Bureaucrat original("Original", 42);
        Bureaucrat copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy:     " << copy     << std::endl;
 
        Bureaucrat assigned("Assigned", 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
 
        // Self-assignment
        assigned = assigned;
    }
 
    // ------------------------------------------------------------------ //
    //  8. Form — valid construction                                      //
    // ------------------------------------------------------------------ //
    section("8. Form valid construction");
    {
        Form f("TaxForm", 50, 25);
        std::cout << "Name:       " << f.getName()      << std::endl;
        std::cout << "Signed:     " << f.isSigned()     << std::endl;
        std::cout << "Sign grade: " << f.getSignGrade() << std::endl;
        std::cout << "Exec grade: " << f.getExecGrade() << std::endl;
    }
 
    // ------------------------------------------------------------------ //
    //  9. Form — grade too high (grade < 1)                              //
    // ------------------------------------------------------------------ //
    section("9. Form grade too high exception");
    {
        try {
            Form bad("BadForm", 0, 50);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Form::GradeTooHighException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
        try {
            Form bad2("BadForm2", 50, 0);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Form::GradeTooHighException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  10. Form — grade too low (grade > 150)                            //
    // ------------------------------------------------------------------ //
    section("10. Form grade too low exception");
    {
        try {
            Form bad("BadForm", 151, 50);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Form::GradeTooLowException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  11. Form — successful sign                                        //
    // ------------------------------------------------------------------ //
    section("11. Form successful sign");
    {
        Bureaucrat b("Signer", 10);
        Form f("ContractForm", 50, 25);
        std::cout << "Signed before: " << f.isSigned() << std::endl;
        f.beSigned(b);
        std::cout << "Signed after:  " << f.isSigned() << std::endl;
    }
 
    // ------------------------------------------------------------------ //
    //  12. Form — bureaucrat grade too low to sign                      //
    // ------------------------------------------------------------------ //
    section("12. Form sign — bureaucrat grade too low");
    {
        Bureaucrat b("LowRanker", 100);
        Form f("TopSecretForm", 10, 5);
        try {
            f.beSigned(b);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Form::GradeTooLowException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
        std::cout << "Form still unsigned: " << f.isSigned() << std::endl;
    }
 
    // ------------------------------------------------------------------ //
    //  13. Form — double sign                                            //
    // ------------------------------------------------------------------ //
    section("13. Form double sign exception");
    {
        Bureaucrat b("Boss", 1);
        Form f("UniqueForm", 1, 1);
        f.beSigned(b);
        std::cout << "Signed: " << f.isSigned() << std::endl;
        try {
            f.beSigned(b);
            std::cout << "ERROR: should have thrown!" << std::endl;
        }
        catch (const Form::doubleSignException& e) {
            std::cout << "Caught expected exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  14. Form — copy constructor & assignment                          //
    // ------------------------------------------------------------------ //
    section("14. Form copy constructor & assignment");
    {
        Bureaucrat b("Bureaucrat", 1);
        Form original("OriginalForm", 50, 25);
        b.getGrade(); // just to use b
 
        Form copy(original);
        std::cout << "Original signed: " << original.isSigned() << std::endl;
        std::cout << "Copy signed:     " << copy.isSigned()     << std::endl;
 
        // Sign the original, copy should be unaffected
        original.beSigned(b);
        Form copy2(original);
        std::cout << "Original signed after sign: " << original.isSigned() << std::endl;
        std::cout << "Copy2 signed (copied after): " << copy2.isSigned()   << std::endl;
 
        // Assignment — only _signed is copied (const members can't be reassigned)
        Form assigned("AssignedForm", 50, 25);
        assigned = original;
        std::cout << "Assigned signed: " << assigned.isSigned() << std::endl;
 
        // Self-assignment
        assigned = assigned;
    }
 
    // ------------------------------------------------------------------ //
    //  15. Edge — bureaucrat at exact boundary signs form at boundary    //
    // ------------------------------------------------------------------ //
    section("15. Boundary: bureaucrat grade == form signGrade");
    {
        Bureaucrat b("ExactFit", 75);
        Form f("BoundaryForm", 75, 75);
        try {
            f.beSigned(b);
            std::cout << "Sign succeeded (grade == signGrade is allowed): "
                      << f.isSigned() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << "Unexpected exception: " << e.what() << std::endl;
        }
    }
 
    std::cout << std::endl;
    std::cout << "All tests done." << std::endl;
    return 0;
}