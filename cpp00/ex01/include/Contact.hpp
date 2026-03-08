/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:27:23 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/08 22:59:00 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define FIRSTNAME	"Enter name: "
# define LASTNAME	"Enter lastname: "
# define NICKNAME	"Enter nickname: "
# define PHONE		"Enter phone: "
# define SECRET		"Enter secret: "

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	Nickname;
	std::string	phone;
	std::string secret;
public:
	void	parseData(std::string const msg, std::string *data);
	bool	addData();
	void	removeData();
	void	printContact()	const;
	void	printData(int index)	const;
	void    printFormat(int width, std::string data)	const;
	void    printFormat(int width, int data) const;
	std::string format(std::string data) const;
	bool	empty()	const;
};
#endif