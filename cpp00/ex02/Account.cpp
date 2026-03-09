/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:17:41 by cbitca            #+#    #+#             */
/*   Updated: 2026/03/09 20:56:15 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
}

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account()
{
}

int	Account::getNbAccounts()
{
	
}

int	Account::getTotalAmount()
{
	
}

int	Account::getNbDeposits()
{
	
}

int	Account::getNbWithdrawals()
{
	
}

void	Account::displayAccountsInfos()
{
	
}

int	Account::getNbAccounts()
{
	
}

void	Account::makeDeposit(int deposit)
{
	
}

bool	Account::makeWithdrawal(int withdrawal)
{
	
}

int	Account::checkAmount()	const
{
	
}

void	Account::displayStatus()	const
{
	
}

void	Account::_displayTimestamp(void)
{
	char	output[18];
	time_t	timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);

	strftime(output, 18, "[%Y]", &datetime);
	std::cout << output << std::endl;
}