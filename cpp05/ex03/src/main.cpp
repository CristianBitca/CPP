/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:16:48 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 16:08:34 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
 
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
    //  1. Intern — construction, copy, assignment                        //
    // ------------------------------------------------------------------ //
    section("1. Intern construction");
    {
        Intern i1;
        Intern i2(i1);
        Intern i3;
        i3 = i1;
        i3 = i3;
    }
 
    // ------------------------------------------------------------------ //
    //  2. Intern — create shrubbery creation form                        //
    // ------------------------------------------------------------------ //
    section("2. Intern makeForm shrubbery creation");
    {
        Intern intern;
        AForm* form = intern.makeForm("shrubbery creation", "garden");
        std::cout << "Form created: " << form->getName() << std::endl;
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  3. Intern — create robotomy request form                          //
    // ------------------------------------------------------------------ //
    section("3. Intern makeForm robotomy request");
    {
        Intern intern;
        AForm* form = intern.makeForm("robotomy request", "Marvin");
        std::cout << "Form created: " << form->getName() << std::endl;
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  4. Intern — create presidential pardon form                       //
    // ------------------------------------------------------------------ //
    section("4. Intern makeForm presidential pardon");
    {
        Intern intern;
        AForm* form = intern.makeForm("presidential pardon", "Zaphod");
        std::cout << "Form created: " << form->getName() << std::endl;
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  5. Intern — unknown form name prints error and returns NULL       //
    // ------------------------------------------------------------------ //
    section("5. Intern makeForm unknown form");
    {
        Intern intern;
        AForm* form = intern.makeForm("coffee request", "Arthur");
        if (form)
            delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  6. Intern — empty string prints error and returns NULL            //
    // ------------------------------------------------------------------ //
    section("6. Intern makeForm empty string");
    {
        Intern intern;
        AForm* form = intern.makeForm("", "target");
        if (form)
            delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  7. Full flow — intern creates, bureaucrat signs and executes      //
    //     shrubbery creation                                             //
    // ------------------------------------------------------------------ //
    section("7. Full flow shrubbery creation");
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form = intern.makeForm("shrubbery creation", "backyard");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  8. Full flow — intern creates, bureaucrat signs and executes      //
    //     robotomy request                                               //
    // ------------------------------------------------------------------ //
    section("8. Full flow robotomy request");
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form = intern.makeForm("robotomy request", "Bender");
        boss.signForm(*form);
        for (int i = 0; i < 5; i++) {
            try {
                boss.executeForm(*form);
            }
            catch (const std::exception& e) {
                std::cerr << "Robotomy failed: " << e.what() << std::endl;
            }
        }
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  9. Full flow — intern creates, bureaucrat signs and executes      //
    //     presidential pardon                                            //
    // ------------------------------------------------------------------ //
    section("9. Full flow presidential pardon");
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form = intern.makeForm("presidential pardon", "Trillian");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  10. Full flow — bureaucrat too low to sign                        //
    // ------------------------------------------------------------------ //
    section("10. Full flow bureaucrat too low to sign");
    {
        Intern intern;
        Bureaucrat lowRank("Intern", 150);
        AForm* form = intern.makeForm("presidential pardon", "Ford");
        lowRank.signForm(*form);
        lowRank.executeForm(*form);
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  11. Full flow — execute without signing                           //
    // ------------------------------------------------------------------ //
    section("11. Full flow execute without signing");
    {
        Intern intern;
        Bureaucrat boss("Boss", 1);
        AForm* form = intern.makeForm("robotomy request", "HAL");
        boss.executeForm(*form);
        delete form;
    }
 
    // ------------------------------------------------------------------ //
    //  12. Multiple interns, multiple forms                              //
    // ------------------------------------------------------------------ //
    section("12. Multiple interns multiple forms");
    {
        Intern i1;
        Intern i2;
        Bureaucrat boss("Boss", 1);
 
        AForm* f1 = i1.makeForm("shrubbery creation", "office");
        AForm* f2 = i1.makeForm("robotomy request", "Dave");
        AForm* f3 = i2.makeForm("presidential pardon", "Slartibartfast");
 
        boss.signForm(*f1);
        boss.signForm(*f2);
        boss.signForm(*f3);
 
        boss.executeForm(*f1);
        boss.executeForm(*f2);
        boss.executeForm(*f3);
 
        delete f1;
        delete f2;
        delete f3;
    }
 
    std::cout << std::endl;
    std::cout << "All tests done." << std::endl;
    return 0;
}