/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 12:32:16 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/05 12:32:24 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP
 
class Base
{
public:
    virtual ~Base();
};
 
class A : public Base
{
};
 
class B : public Base
{
};
 
class C : public Base
{
};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);
 
#endif