/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:36:51 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 13:37:01 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM__H
#define ROBOTOMYREQUESTFORM__H

#include <iostream>
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& name);
	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	void execute(Bureaucrat const & executor) const;

	class RobotomyExecuteException: public std::exception
	{
		const char* what() const throw();
	};

	~RobotomyRequestForm();
};

#endif