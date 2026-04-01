/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 14:56:21 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/01 09:47:15 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERT_HPP__
# define __SCALARCONVERT_HPP__
 
#include <string>
#include <cerrno>
#include <limits>
#include <limits.h>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <iostream>
 
class ScalarConvert
{
private:
    enum type
    {
        UNKNOWN,
        CHAR,
        INT,
        FLOAT,
        DOUBLE
    };
    static bool    isChar(const std::string& value);
    static bool    isInt(const std::string& value);
    static bool    isFloat(const std::string& value);
    static bool    isDouble(const std::string& value);
    static type    isType(const std::string& value);
 
    static char    toChar(const std::string& value);
 
    static int     toInt(const std::string& value);
    static int     toInt(double value);
    static int     toInt(float value);
    static int     toInt(char value);
    
    static float   toFloat(const std::string& value);
    static float   toFloat(double value);
    static float   toFloat(int value);
 
    static double  toDouble(const std::string& value);
    static double  toDouble(float value);
    static double  toDouble(int value);
    
    static void    printTypes(int value);
    static void    printTypes(float value);
    static void    printTypes(double value);
    static void    printTypes(char value);
public:
    static void convert(const std::string& value);
};
 
#endif