/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 17:27:23 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/03 17:27:26 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	firstName;
	std::string	lastName;
	std::string	Nickname;
	std::string	phone;
	std::string secret;
public:
	Contact();
	void	addData();
	void	printData()	const;
};
#endif