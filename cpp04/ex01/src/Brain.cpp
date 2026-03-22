/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 12:11:18 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/22 12:51:00 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    for (int i = 0; i < 100; i++) {
        _ideas[i] = "Empty";
    }
    std::cout << "Brain construstor was called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++) {
        _ideas[i] = other._ideas[i];
    }
    std::cout << "Brain copy construstor was called" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            _ideas[i] = other._ideas[i];
        }
        std::cout << "Brain copy assigment construstor was called" << std::endl;
    }
    else {
        std::cout << "Brain copy assignment operator: self-assignment ignored" << std::endl;
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor was called" << std::endl;
}

void    Brain::setIdea(int i, std::string idea)
{
    if (i >= 100 || i < 0) {
        std::cout << "Index ou of range" << std::endl;
        return ;
    }
    _ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
    if (i >= 100 || i < 0) {
        std::cout << "Index ou of range" << std::endl;
        return "";
    }
    return _ideas[i];
}
