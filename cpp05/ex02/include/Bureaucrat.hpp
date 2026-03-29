/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:14:57 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 14:02:17 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class  Bureaucrat
{
private:
    std::string  _name;
    int _grade;
public:
    // Constructors
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    // Destructors
    ~Bureaucrat();
    // Getters
    int getGrade() const;
    const std::string& getName() const;
    //Increments
    void incrementGrade();
    void decrementGrade();
    
    void signForm(AForm& form);
	void executeForm(const AForm& form) const;
    //Exception
    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif