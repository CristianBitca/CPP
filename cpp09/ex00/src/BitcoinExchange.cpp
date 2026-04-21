/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:50:55 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/21 21:21:56 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& db_filename)
{
    loadDatabase(db_filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void    BitcoinExchange::loadDatabase(const std::string& filename)
{
    if (filename.empty())
        throw ERR_DB_EMPTY;
    std::ifstream   file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error(filename + " could not open file.");
    }
    std::string line;
    if (!std::getline(file, line)) {
        throw ERR_DB_LINE;
    }
    if (line != DB_HEADER) {
        throw ERR_DB_NOT;
    }
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t pos = line.find(',');
        if (pos == std::string::npos) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }
        std::string date_str = line.substr(0, pos);
        std::string rate_str = line.substr(pos + 1);
        if (!isValidDateString(date_str)) {
            std::cerr << "Invalid date: " << date_str << std::endl;
            continue;
        }
        char* end;
        float rate = static_cast<float>(std::strtod(rate_str.c_str(), &end));
        if (*end != '\0' && *end != '\n' && *end != '\r') {
            std::cerr << "Invalid rate: " << rate_str << std::endl;
            continue;
        }
        _database[date_str] = rate;
    }
    file.close();
    if (_database.empty()) {
        throw std::runtime_error("Database is empty");
    }
}

bool    BitcoinExchange::isValidDateString(const std::string& date) const
{
    if (date.size() != 10 || std::count(date.begin(), date.end(), '-') != 2)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    std::string year_str = date.substr(0, 4);
    std::string month_str = date.substr(5, 2);
    std::string day_str = date.substr(8, 2);
    for (size_t i = 0; i < year_str.size(); ++i)
        if (!std::isdigit(year_str[i])) return false;
    for (size_t i = 0; i < month_str.size(); ++i)
        if (!std::isdigit(month_str[i])) return false;
    for (size_t i = 0; i < day_str.size(); ++i)
        if (!std::isdigit(day_str[i])) return false;
    int year = std::atoi(year_str.c_str());
    int month = std::atoi(month_str.c_str());
    int day = std::atoi(day_str.c_str());
    if (year < 1000 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    return true;
}

void    BitcoinExchange::parseInput(const std::string& filename)
{
    if (filename.empty())
        throw ERR_IN_EMPTY;
    std::ifstream   file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error(filename + " could not open file.");
    }
    std::string line;
    if (!std::getline(file, line)) {
        throw ERR_IN_LINE;
    }
    if (line != IN_HEADER) {
        throw ERR_IN_NOT;
    }
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Invalid line format: " << line << std::endl;
            continue;
        }
        std::string date_str = line.substr(0, pos - 1);
        std::string value_str = line.substr(pos + 2);
        if (!isValidDateString(date_str)) {
            std::cerr << "Error: bad input => " << date_str << std::endl;
            continue;
        }
        char* end;
        float value = static_cast<float>(std::strtod(value_str.c_str(), &end));
        if (*end != '\0' && *end != '\n' && *end != '\r') {
            std::cerr << "Error: bad input => " << value_str << std::endl;
            continue;
        }
        if (!isValidValue(value)) {
            continue;
        }
        try {
            float rate = getRateForDate(date_str);
            float result = value * rate;
            
            // Output in required format
            std::cout << date_str << " => " << value << " = " << result << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } 
    file.close();
}


bool BitcoinExchange::isValidValue(float value) const
{
    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

float   BitcoinExchange::getRateForDate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _database.find(date);
    
    if (it != _database.end()) {
        return it->second;
    }
    it = _database.lower_bound(date);
    if (it == _database.begin()) {
        throw std::runtime_error("No data available for this date");
    }
    --it;
    return it->second;
}