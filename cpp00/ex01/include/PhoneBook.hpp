/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:12:13 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/18 16:38:41 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

#define MAX_CONTACTS 8

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
	int		i;
public:
	PhoneBook();
	~PhoneBook();
	void		createPhoneBook();
	commands	parsecommands();
	void		addContact();
	void		searchContact() const;
	void		printContacts() const;
	void		printHeader() const;
};

#endif

