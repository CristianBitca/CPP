/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:31:42 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/25 14:58:21 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade)
    : _name(name),
      _signGrade(signGrade),
      _execGrade(execGrade)
{
    if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw GradeTooLowException();
    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw GradeTooHighException();
    _signed = false;
    std::cout << "AForm: constructor was called" << std::endl;
}

AForm::AForm(const AForm& other)
    :   _name(other._name),
        _signGrade(other._signGrade),
        _execGrade(other._execGrade)
{
    _signed = other._signed;
    std::cout << "AForm: copy constructor was called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other) {
        _signed = other._signed;
        std::cout << "AForm: copy assigment operator was called" << std::endl;
    }
    else {
        std::cout << "AForm: copy assigment operator: self-asigment ignored" << std::endl;
    }
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool    AForm::isSigned() const
{
    return _signed;
}

int AForm::getSignGrade()    const
{
    return _signGrade;    
}

int AForm::getExecGrade()    const
{
    return _execGrade;
}

void    AForm::beSigned(const Bureaucrat& b)
{
    if (_signed) {
        throw   doubleSignException();
    }
    if (b.getGrade() > _signGrade) {
        throw   GradeTooLowException();
    }
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::doubleSignException::what() const throw()
{
    return "Double sign";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "form not signed";
}

AForm::~AForm()
{
    std::cout << "AForm: destructor was called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "AForm: " << f.getName()
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade()
       << ", signed: " << (f.isSigned() ? "yes" : "no");
    return os;
}