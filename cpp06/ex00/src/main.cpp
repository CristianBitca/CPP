/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:08:17 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/30 15:11:35 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConvert.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Wrong amount of arguments." << std::endl;
        return (1);
    }
    ScalarConvert::convert(argv[1]);
    return (0);
}