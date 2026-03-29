/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:36:16 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 13:36:28 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM__H
#define PRESIDENTIALPARDONFORM__H

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& name);
	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	void execute(const Bureaucrat& executor) const;

	~PresidentialPardonForm();
};

#endif