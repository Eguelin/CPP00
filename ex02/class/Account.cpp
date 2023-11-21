/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:23:08 by eguelin           #+#    #+#             */
/*   Updated: 2023/11/21 20:03:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/* ************************************************************************** */
/*                       Public static member functions                       */
/* ************************************************************************** */

int	Account::getNbAccounts( void ) {return (Account::_nbAccounts);}

int	Account::getTotalAmount( void ) {return (Account::_totalAmount);}

int	Account::getNbDeposits( void ) {return (Account::_totalNbDeposits);}

int	Account::getNbWithdrawals( void ) {return (Account::_totalNbWithdrawals);}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";"\
				"total:" << Account::_totalAmount << ";"\
				"deposits:" << Account::_totalNbDeposits << ";"\
				"withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

/* ************************************************************************** */
/*                         Constructors & Destructors                         */
/* ************************************************************************** */

Account::Account( int initial_deposit )
{
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
				"amount:" << this->_amount << ";"\
				"created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
				"amount:" << this->_amount << ";"\
				"closed" << std::endl;
}

/* ************************************************************************** */
/*                           Public member functions                          */
/* ************************************************************************** */

void	Account::makeDeposit( int deposit )
{
	this->_nbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
				"p_amount:" << this->_amount << ";"\
				"deposit:" << deposit << ";"\
				"amount:" << this->_amount + deposit << ";"\
				"nb_deposits:" << this->_nbDeposits << std::endl;

	this->_totalAmount += deposit;
	this->_amount += deposit;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();

	if (withdrawal <= this->_amount)
	{
		this->_nbWithdrawals++;

		std::cout << "index:" << this->_accountIndex << ";"\
					"p_amount:" << this->_amount << ";"\
					"withdrawal:" << withdrawal << ";"\
					"amount:" << this->_amount - withdrawal << ";"\
					"nb_withdrawals:" << this->_nbWithdrawals << std::endl;

		this->_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_totalNbWithdrawals++;
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";"\
					"p_amount:" << this->_amount << ";"\
					"withdrawal:refused" << std::endl;

		return (false);
	}

	return (true);
}

int		Account::checkAmount( void ) const
{
	return(this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"\
				"amount:" << this->_amount << ";"\
				"deposits:" << this->_nbDeposits << ";"\
				"withdrawals:" << this->_nbWithdrawals << std::endl;
}


/* ************************************************************************** */
/*                       Private static member variables                      */
/* ************************************************************************** */

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* ************************************************************************** */
/*                       Private static member functions                      */
/* ************************************************************************** */

void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
    char timestamp[19];

    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S] ", std::localtime(&now));

	std::cout << timestamp ;
}


