/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 18:43:58 by cbitca            #+#    #+#             */
/*   Updated: 2026/04/21 21:23:02 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

#define DB_HEADER   "date,exchange_rate"
#define IN_HEADER   "date | value" 

#define ERR_DB_EMPTY std::runtime_error("Database filename is empty")
#define ERR_DB_LINE std::runtime_error("Database file is empty")
#define ERR_DB_NOT std::runtime_error("Invalid database header")

#define ERR_IN_NOT std::runtime_error("Invalid input file header")
#define ERR_IN_EMPTY std::runtime_error("Input filename is empty")
#define ERR_IN_LINE std::runtime_error("Input file is empty")

#define ERR "Error: "
#define ERR_INPUT   "Bad input => "

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

    bool    isValidDateString(const std::string& date) const;
    bool    isValidValue(float value) const;

    void    loadDatabase(const std::string& filename);
    float   getRateForDate(const std::string& date) const;
public:
    BitcoinExchange(const std::string& db_filename);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void    parseInput(const std::string& filename);
};

#endif