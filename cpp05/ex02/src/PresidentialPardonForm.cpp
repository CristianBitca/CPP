/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:55:38 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 13:55:59 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidental_default", 25, 5)
{
    std::cout << "PresidentialPardonForm: default constructor was called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name) : AForm(name, 25, 5)
{
    std::cout << "PresidentialPardonForm: constructor was called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other)
{
    std::cout << "PresidentialPardonForm: copy constructor was called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        std::cout << "PresidentialPardonForm: copy assigment operator was called" << std::endl;
    }
    else {
        std::cout << "PresidentialPardonForm: copy assigment operator: self-asigment ignored" << std::endl;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::cout << getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm: destructor was called" << std::endl;
}