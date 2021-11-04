/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 14:04:05 by agautier          #+#    #+#             */
/*   Updated: 2021/11/04 21:15:04 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

static void	get_timestamp(void)
{
	struct tm*	timeinfo;
	time_t		rawtime;
	char		ts[19];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(ts, 19, "[%Y%m%d_%I%M%S] ", timeinfo);
	std::cout << ts;
}

/*
**	Static vars.
*/
int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

/*
**	Default private constructor.
*/
Account::Account(void)
{
}

/*
**	Constructor with initial_deposit.
*/
Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts++),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	get_timestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created"
		<< std::endl;
	_totalAmount += _amount;
}

/*
**	Default destructor.
*/
Account::~Account(void)
{
	get_timestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed"
		<< std::endl;
}

/*
**	Display accounts infos.
*/
void	Account::displayAccountsInfos(void)
{
	get_timestamp();
	std::cout
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

/*
**	Deposit money to account.
*/
void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	get_timestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount  + deposit << ";"
		<< "nb_deposits:" << this->_nbDeposits
		<< std::endl;
	this->_amount += deposit;
	_totalAmount += deposit;
}

/*
**	Withdraw money from account.
*/
bool	Account::makeWithdrawal(int withdrawal)
{
	get_timestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout
		<< withdrawal << ";"
		<< "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals
		<< std::endl;
	return (true);
}

/*
**	Check amount of money from account.
*/
int	Account::checkAmount(void) const
{
	return (_amount);
}

/*
**	Display status 
*/
void	Account::displayStatus(void) const
{
	get_timestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

/*
**	Getter for _nbAccounts.
*/
int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

/*
**	Getter for _nbAccounts.
*/
int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

/*
**	Getter for _totalNbDeposits.
*/
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

/*
**	Getter for _totalNbWithdrawals.
*/
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
