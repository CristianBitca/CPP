/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:09:02 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/25 14:54:25 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _signGrade;
    const int           _execGrade;
public:
    Form(std::string name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    std::string getName()   const;
    bool        isSigned()  const;
    int         getSignGrade()  const;
    int         getExecGrade()  const;

    void    beSigned(const Bureaucrat& b);

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
    class doubleSignException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif