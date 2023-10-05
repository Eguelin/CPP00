/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:23:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/10/05 13:02:42 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	Account::_nbAccounts += 1;
	Account::_totalAmount += initial_deposit;
	Account::_accountIndex = Account::_nbAccounts - 1;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_nbDeposits += 1;

	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";deposit:" << deposit << ";amount:" << Account::_amount + deposit << ";nb_deposits:" << Account::_nbDeposits << std::endl;

	Account::_totalAmount += deposit;
	Account::_amount += deposit;
	Account::_totalNbDeposits += 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	if (withdrawal <= Account::_amount)
	{
		Account::_nbWithdrawals += 1;

		std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";withdrawal:" << withdrawal << ";amount:" << Account::_amount - withdrawal << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;

		Account::_totalAmount -= withdrawal;
		Account::_amount -= withdrawal;
		Account::_totalNbWithdrawals += 1;
	}
	else
	{
		std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";withdrawal:refused" << std::endl;

		return (false);
	}

	return (true);
}

int		Account::checkAmount( void ) const
{
	return(Account::_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
    char timestamp[19];

    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", std::localtime(&now));

	std::cout << timestamp ;
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
