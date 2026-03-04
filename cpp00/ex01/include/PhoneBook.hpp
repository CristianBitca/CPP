/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:12:13 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/03 17:12:14 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

typedef	enum e_commands
{
	UNKNOWN,
	ADD,
	SEARCH,
	EXIT
}	commands;


class PhoneBook
{
private:
	Contact	contact[8];
	int		count;
	int		old;
public:
	PhoneBook();
	commands	parsecommands();
	void		addContact();
	void		searchContact();
};

#endif

