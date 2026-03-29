/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:09:02 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/25 14:54:25 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
    const std::string   _name;
    bool                _signed;
    const int           _signGrade;
    const int           _execGrade;
public:
    AForm(std::string name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    std::string getName()   const;
    bool        isSigned()  const;
    int         getSignGrade()  const;
    int         getExecGrade()  const;

    virtual void    execute(const Bureaucrat& execute) const= 0;
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
    class FormNotSignedException : public std::exception
	{
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif