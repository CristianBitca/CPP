/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:37:42 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/10 19:11:29 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Expected ./HArlFilter <param>" << std::endl;
		return 1;
	}

	Harl harl;

	harl.complain(std::string(argv[1]));
	return (0);	
}