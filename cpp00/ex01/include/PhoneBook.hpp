/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:12:13 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/08 21:53:16 by cbitca           ###   ########.fr       */
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
	void		createPhoneBook();
	commands	parsecommands();
	void		addContact();
	void		searchContact() const;
	void		printContacts() const;
	void		printHeader() const;
};

#endif

