/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:06:21 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/20 18:36:06 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
 
 
bool    ScalarConvert::isChar(const std::string& value)
{
    if (value.size() == 3 && value[0] == '\'' && value[2] == '\'') {
        return std::isprint(static_cast<unsigned char>(value[1]));
    }
    if (value.size() == 1 && std::isprint(static_cast<unsigned char>(value[0])) && !std::isdigit(value[0])) {
        return true;
    }
    return false;
} 
 
bool    ScalarConvert::isInt(const std::string& value)
{
    char    *endptr = NULL;
    errno = 0;
    long res = std::strtol(value.c_str(), &endptr, 10);
    return *endptr == '\0' && errno == 0 && (INT_MAX >= res && INT_MIN <= res);
}
 
bool    ScalarConvert::isFloat(const std::string& value)
{
    char    *endptr = NULL;
    errno = 0;
    if (value == "-inff" || value == "+inff" || value == "nanf") {
        return true;
    }
    if (value.find('.') == std::string::npos)
        return false;
    std::strtof(value.c_str(), &endptr);
    return *endptr == 'f' && *(endptr + 1) == '\0' && errno == 0;
}
 
bool    ScalarConvert::isDouble(const std::string& value)
{
    char    *endptr = NULL;
    errno = 0;
    if (value == "-inf" || value == "+inf" || value == "nan") {
        return true;
    }
    if (value.find('.') == std::string::npos)
        return false;
    std::strtod(value.c_str(), &endptr);
    return *endptr == '\0' && errno == 0;
}
 
ScalarConvert::type   ScalarConvert::isType(const std::string& value)
{
    if (isChar(value))
        return CHAR;
    else if (isInt(value))
        return INT;
    else if (isFloat(value))
        return FLOAT;
    else if (isDouble(value))
        return DOUBLE;
    return UNKNOWN;
}
 
int    ScalarConvert::toInt(const std::string& value)
{
    if (isInt(value)) {
        char *endptr;
        return static_cast<int>(std::strtol(value.c_str(), &endptr, 10));
    }
    throw "Invalid argument type Int";
}
 
int    ScalarConvert::toInt(double value)
{
    if (std::isnan(value)) {
        throw "nan";
    }
    if (std::isinf(value)) {
        throw "inf";
    }
    if (value >= static_cast<double>(std::numeric_limits<int>::min()) &&
        value <= static_cast<double>(std::numeric_limits<int>::max())) {
        return static_cast<int>(value);
    }
    throw "Integer overflow occurred";
}
 
int    ScalarConvert::toInt(float value)
{
    if (std::isnan(value)) {
        throw "nan";
    }
    if (std::isinf(value)) {
        throw "inf";
    }
    if (value >= static_cast<float>(std::numeric_limits<int>::min()) &&
        value <= static_cast<float>(std::numeric_limits<int>::max())) {
        return static_cast<int>(value);
    }
    throw "Integer overflow occurred";
}

int    ScalarConvert::toInt(char value)
{
    return static_cast<int>(value);
}
 
char    ScalarConvert::toChar(const std::string& value)
{
    if (isprint(value[1]))
        return value[1];
    int tmp = toInt(value);
    if (tmp >= std::numeric_limits<char>::min() && tmp <= std::numeric_limits<char>::max()) {
        return static_cast<char>(tmp);
    }
    throw "Char overflow occurred";
}
 
float    ScalarConvert::toFloat(const std::string& value)
{
    if (isFloat(value)) {
        char *endptr;
        return static_cast<float>(std::strtof(value.c_str(), &endptr));
    }
    throw "Invalid argument type Float";
}
 
float   ScalarConvert::toFloat(int value)
{
    std::cout << static_cast<float>(value) << std::endl;
    return static_cast<float>(value);
}
 
float   ScalarConvert::toFloat(double value)
{
    if (std::isnan(value) || std::isinf(value))
        return static_cast<float>(value);
    if (value >= -static_cast<double>(std::numeric_limits<float>::max()) &&
        value <= static_cast<double>(std::numeric_limits<float>::max())) {
        return static_cast<float>(value);
    }
    throw "Float overflow occurred";
}
 
double    ScalarConvert::toDouble(const std::string& value)
{
    if (isDouble(value)) {
        char *endptr;
        return static_cast<double>(std::strtod(value.c_str(), &endptr));
    }
    throw "Invalid argument type Double";
}
 
double    ScalarConvert::toDouble(int value)
{
    return static_cast<double>(value);
}
 
double    ScalarConvert::toDouble(float value)
{
    return static_cast<double>(value);
}
 
void    ScalarConvert::printTypes(int value)
{
    if (value >= 0 && value <= 127) {
        if (std::isprint(static_cast<char>(value)))
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: impossible" << std::endl;
    }
    std::cout << "int: " << value << std::endl;
    float f = toFloat(value);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    double d = toDouble(value);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
 
void    ScalarConvert::printTypes(float value)
{
    try {
        int tmp = toInt(value);
        if (tmp >= 0 && tmp <= 127) {
            if (std::isprint(static_cast<char>(tmp)))
                std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
    }
    try {
        std::cout << "int: " << toInt(value) << std::endl;
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
    double d = toDouble(value);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
 
void    ScalarConvert::printTypes(double value)
{
    try {
        int tmp = toInt(value);
        if (tmp >= 0 && tmp <= 127) {
            if (std::isprint(static_cast<char>(tmp)))
                std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
            else
                std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: impossible" << std::endl;
        }
    } catch (...) {
        std::cout << "char: impossible" << std::endl;
    }
    try {
        std::cout << "int: " << toInt(value) << std::endl;
    } catch (...) {
        std::cout << "int: impossible" << std::endl;
    }
    try {
        float f = toFloat(value);
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    } catch (...) {
        std::cout << "float: impossible" << std::endl;
    }
    std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
}
 
void    ScalarConvert::printTypes(char value)
{
    try
    {
        std::cout << "char: '" << value << "'" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    int intVal = toInt(value);
    std::cout << "int: " << intVal << std::endl;
    float f = toFloat(intVal);
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    double d = toDouble(intVal);
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
 
void    ScalarConvert::convert(const std::string& value)
{
    switch (isType(value))
    {
    case CHAR:
        {
            char tmp = toChar(value);
            printTypes(tmp);
        }
        break;
    case INT:
        {
            int tmp = toInt(value);
            printTypes(tmp);
        }
        break;
    case FLOAT:
        {
            float tmp = toFloat(value);
            printTypes(tmp);
        }
        break;
    case DOUBLE:
        {
            double tmp = toDouble(value);
            printTypes(tmp);
        }
        break;    
    default:
        std::cout << "Error: Unknown type" << std::endl;
        break;
    }
}