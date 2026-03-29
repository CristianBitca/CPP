/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:16:48 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 14:00:32 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
 
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
    //  1. ShrubberyCreationForm — valid construction                     //
    // ------------------------------------------------------------------ //
    section("1. ShrubberyCreationForm construction");
    {
        ShrubberyCreationForm s1;
        ShrubberyCreationForm s2("garden");
        ShrubberyCreationForm s3(s2);
        ShrubberyCreationForm s4("tmp");
        s4 = s2;
        s4 = s4;
    }
 
    // ------------------------------------------------------------------ //
    //  2. ShrubberyCreationForm — execute unsigned form                  //
    // ------------------------------------------------------------------ //
    section("2. ShrubberyCreationForm execute unsigned");
    {
        Bureaucrat b("Alice", 1);
        ShrubberyCreationForm f("park");
        try {
            f.execute(b);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  3. ShrubberyCreationForm — grade too low to sign                  //
    // ------------------------------------------------------------------ //
    section("3. ShrubberyCreationForm grade too low to sign");
    {
        Bureaucrat b("Bob", 150);
        ShrubberyCreationForm f("forest");
        b.signForm(f);
    }
 
    // ------------------------------------------------------------------ //
    //  4. ShrubberyCreationForm — grade too low to execute               //
    // ------------------------------------------------------------------ //
    section("4. ShrubberyCreationForm grade too low to execute");
    {
        Bureaucrat signer("Signer", 145);
        Bureaucrat executor("Executor", 138);
        ShrubberyCreationForm f("meadow");
        signer.signForm(f);
        try {
            f.execute(executor);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  5. ShrubberyCreationForm — full success                           //
    // ------------------------------------------------------------------ //
    section("5. ShrubberyCreationForm full success");
    {
        Bureaucrat b("Charlie", 1);
        ShrubberyCreationForm f("home");
        b.signForm(f);
        b.executeForm(f);
    }
 
    // ------------------------------------------------------------------ //
    //  6. RobotomyRequestForm — valid construction                       //
    // ------------------------------------------------------------------ //
    section("6. RobotomyRequestForm construction");
    {
        RobotomyRequestForm r1;
        RobotomyRequestForm r2("Bender");
        RobotomyRequestForm r3(r2);
        RobotomyRequestForm r4("tmp");
        r4 = r2;
        r4 = r4;
    }
 
    // ------------------------------------------------------------------ //
    //  7. RobotomyRequestForm — execute unsigned form                    //
    // ------------------------------------------------------------------ //
    section("7. RobotomyRequestForm execute unsigned");
    {
        Bureaucrat b("Alice", 1);
        RobotomyRequestForm f("R2D2");
        try {
            f.execute(b);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  8. RobotomyRequestForm — grade too low to sign                    //
    // ------------------------------------------------------------------ //
    section("8. RobotomyRequestForm grade too low to sign");
    {
        Bureaucrat b("Bob", 150);
        RobotomyRequestForm f("C3PO");
        b.signForm(f);
    }
 
    // ------------------------------------------------------------------ //
    //  9. RobotomyRequestForm — grade too low to execute                 //
    // ------------------------------------------------------------------ //
    section("9. RobotomyRequestForm grade too low to execute");
    {
        Bureaucrat signer("Signer", 72);
        Bureaucrat executor("Executor", 46);
        RobotomyRequestForm f("HAL");
        signer.signForm(f);
        try {
            f.execute(executor);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  10. RobotomyRequestForm — full success (run a few times)          //
    // ------------------------------------------------------------------ //
    section("10. RobotomyRequestForm full success (5 attempts)");
    {
        Bureaucrat b("Charlie", 1);
        RobotomyRequestForm f("Marvin");
        b.signForm(f);
        for (int i = 0; i < 5; i++) {
            try {
                f.execute(b);
            }
            catch (const std::exception& e) {
                std::cerr << "Robotomy failed: " << e.what() << std::endl;
            }
        }
    }
 
    // ------------------------------------------------------------------ //
    //  11. PresidentialPardonForm — valid construction                   //
    // ------------------------------------------------------------------ //
    section("11. PresidentialPardonForm construction");
    {
        PresidentialPardonForm p1;
        PresidentialPardonForm p2("Arthur Dent");
        PresidentialPardonForm p3(p2);
        PresidentialPardonForm p4("tmp");
        p4 = p2;
        p4 = p4;
    }
 
    // ------------------------------------------------------------------ //
    //  12. PresidentialPardonForm — execute unsigned form                //
    // ------------------------------------------------------------------ //
    section("12. PresidentialPardonForm execute unsigned");
    {
        Bureaucrat b("Alice", 1);
        PresidentialPardonForm f("Ford Prefect");
        try {
            f.execute(b);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  13. PresidentialPardonForm — grade too low to sign                //
    // ------------------------------------------------------------------ //
    section("13. PresidentialPardonForm grade too low to sign");
    {
        Bureaucrat b("Bob", 150);
        PresidentialPardonForm f("Trillian");
        b.signForm(f);
    }
 
    // ------------------------------------------------------------------ //
    //  14. PresidentialPardonForm — grade too low to execute             //
    // ------------------------------------------------------------------ //
    section("14. PresidentialPardonForm grade too low to execute");
    {
        Bureaucrat signer("Signer", 25);
        Bureaucrat executor("Executor", 6);
        PresidentialPardonForm f("Zaphod");
        signer.signForm(f);
        try {
            f.execute(executor);
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }
 
    // ------------------------------------------------------------------ //
    //  15. PresidentialPardonForm — full success                         //
    // ------------------------------------------------------------------ //
    section("15. PresidentialPardonForm full success");
    {
        Bureaucrat b("Charlie", 1);
        PresidentialPardonForm f("Marvin");
        b.signForm(f);
        b.executeForm(f);
    }
 
    // ------------------------------------------------------------------ //
    //  16. signForm / executeForm via Bureaucrat — all three forms       //
    // ------------------------------------------------------------------ //
    section("16. signForm + executeForm through Bureaucrat");
    {
        Bureaucrat boss("Boss", 1);
 
        ShrubberyCreationForm    s("office");
        RobotomyRequestForm      r("Dave");
        PresidentialPardonForm   p("Slartibartfast");
 
        boss.signForm(s);
        boss.signForm(r);
        boss.signForm(p);
 
        boss.executeForm(s);
        boss.executeForm(r);
        boss.executeForm(p);
    }
 
    // ------------------------------------------------------------------ //
    //  17. Double sign                                                    //
    // ------------------------------------------------------------------ //
    section("17. Double sign");
    {
        Bureaucrat b("Alice", 1);
        PresidentialPardonForm f("Deep Thought");
        b.signForm(f);
        b.signForm(f);
    }
 
    std::cout << std::endl;
    std::cout << "All tests done." << std::endl;
    return 0;
}