/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 13:31:42 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/25 14:58:21 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade)
    : _name(name),
      _signGrade(signGrade),
      _execGrade(execGrade)
{
    if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
        throw GradeTooLowException();
    if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
        throw GradeTooHighException();
    _signed = false;
    std::cout << "Form: constructor was called" << std::endl;
}

Form::Form(const Form& other)
    :   _name(other._name),
        _signGrade(other._signGrade),
        _execGrade(other._execGrade)
{
    _signed = other._signed;
    std::cout << "Form: copy constructor was called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    if (this != &other) {
        _signed = other._signed;
        std::cout << "Form: copy assigment operator was called" << std::endl;
    }
    else {
        std::cout << "Form: copy assigment operator: self-asigment ignored" << std::endl;
    }
    return *this;
}

std::string Form::getName() const
{
    return _name;
}

bool    Form::isSigned() const
{
    return _signed;
}

int Form::getSignGrade()    const
{
    return _signGrade;    
}

int Form::getExecGrade()    const
{
    return _execGrade;
}

void    Form::beSigned(const Bureaucrat& b)
{
    if (_signed) {
        throw   doubleSignException();
    }
    if (b.getGrade() > _signGrade) {
        throw   GradeTooLowException();
    }
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* Form::doubleSignException::what() const throw()
{
    return "Double sign";
}

Form::~Form()
{
    std::cout << "Form: destructor was called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Form: " << f.getName()
       << ", sign grade: " << f.getSignGrade()
       << ", exec grade: " << f.getExecGrade()
       << ", signed: " << (f.isSigned() ? "yes" : "no");
    return os;
}