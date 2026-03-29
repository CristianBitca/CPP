/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:37:12 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 13:54:19 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM__H
#define SHRUBBERYCREATIONFORM__H

#include <iostream>
#include <string>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& name);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	void execute(const Bureaucrat& executor) const;

	~ShrubberyCreationForm();
};

#endif