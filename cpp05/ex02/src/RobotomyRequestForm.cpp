/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:57:05 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 13:57:35 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robot", 72, 45)
{
    std::cout << "RobotomyRequestForm: default constructor was called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name) : AForm(name, 72, 45)
{
    std::cout << "RobotomyRequestForm: constructor was called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other)
{
    std::cout << "RobotomyRequestForm: copy constructor was called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other) {
        AForm::operator=(other);
        std::cout << "RobotomyRequestForm: copy assigment operator was called" << std::endl;
    }
    else {
        std::cout << "RobotomyRequestForm: copy assigment operator: self-asigment ignored" << std::endl;
    }
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    std::srand(std::time(0));
    if (std::rand() % 50)
        std::cout << getName() << " has been robotomized successfully" << std::endl;
    else
        throw RobotomyExecuteException();
}

const char* RobotomyRequestForm::RobotomyExecuteException::what() const throw()
{
    return "faild to execute";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm: destructor was called" << std::endl;
}