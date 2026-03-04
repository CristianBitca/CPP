/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:34:54 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/03 15:34:55 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{ for (int i = 1; argv[i]; i++)
		for (int y = 0; argv[i][y]; y++)
			std::cout << (char)toupper(argv[i][y]);
		std::cout << std::endl; }
	return (EXIT_SUCCESS);
}
