/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 16:01:25 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 16:07:29 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    std::cout << "Intern: default constructor was called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    (void)other;
    std::cout << "Intern: copy constructor was called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
        std::cout << "Intern: copy assigment operator was called" << std::endl;
    else
        std::cout << "Intern: copy assigment operator: self-asigment ignored" << std::endl;
    return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    const std::string names[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++)
    {
        if (names[i] != name)
            continue;
        switch (i)
        {
            case 0:
                std::cout << "Intern creates " << name << std::endl;
                return new ShrubberyCreationForm(target);
            case 1:
                std::cout << "Intern creates " << name << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "Intern creates " << name << std::endl;
                return new PresidentialPardonForm(target);
        }
    }
    std::cerr << "Intern: form " << name << " doesn't exist" << std::endl;
    return NULL;
}

Intern::~Intern()
{
    std::cout << "Intern: destructor was called" << std::endl;
}