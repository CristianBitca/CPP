/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 15:53:16 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/29 16:07:23 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN__H
#define INTERN__H

#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm*  makeForm(const std::string& name, const std::string& target);
};

#endif