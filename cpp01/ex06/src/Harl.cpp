/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:37:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/10 19:16:18 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl; 
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl; 
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	list[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int	n;
	for (n = 0; n < 4; n++) {
		if (level == list[n]) {
			break;
		}
	}

	switch (n)
	{
	case 0:
		std::cout << "[ DEBUG ]" << std::endl;
		debug();
		std::cout << std::endl << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl << "[ ERROR ]" << std::endl;
		error();
		break;
	case 1:
		std::cout << "[ INFO ]" << std::endl;
		info();
		std::cout << std::endl << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl << "[ ERROR ]" << std::endl;
		error();
		break;
	case 2:
		std::cout << "[ WARNING ]" << std::endl;
		warning();
		std::cout << std::endl << "[ ERROR ]" << std::endl;
		error();
		break;
	case 3:
		std::cout << "[ ERROR ]" << std::endl;
		error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}
}