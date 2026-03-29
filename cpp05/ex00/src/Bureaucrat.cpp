/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:14:55 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/25 10:06:54 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    if (grade < MAX_GRADE) {
        throw GradeTooHighException();
    }
    if (grade > MIN_GRADE) {
        throw GradeTooLowException();
    }
    _name = name;
    _grade = grade;
    std::cout << "Bureaucrat: constructor was called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat: copy constructor was called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other) {
        _name = other._name;
        _grade = other._grade;
        std::cout << "Bureaucrat: copy assigment operator was called" << std::endl;
    }
    else {
        std::cout << "Bureaucrat: copy assigment operator: self-asigment ignored" << std::endl;
    }
    return *this;
}

int    Bureaucrat::getGrade()  const
{
    return _grade;
}

const std::string&    Bureaucrat::getName() const
{
    return _name;
}

void    Bureaucrat::incrementGrade()
{
    if (_grade <= MAX_GRADE)
        throw GradeTooHighException();
    _grade--;
}

void    Bureaucrat::decrementGrade()
{
    if (_grade >= MIN_GRADE)
        throw GradeTooLowException();
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: destructor was called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ". bureaucrat grade " << b.getGrade();
    return os;  
}