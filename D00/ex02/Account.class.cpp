/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 14:51:43 by ofedorov          #+#    #+#             */
/*   Updated: 2018/10/02 18:14:41 by eebersol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <vector>
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex 	= _nbAccounts;
	_nbAccounts++;
	_totalAmount 			+= initial_deposit;
	_amount 				= initial_deposit;
	_totalNbDeposits 		= 0;
	_totalNbWithdrawals 	= 0;
	_nbDeposits 			= 0;
	_nbWithdrawals 			= 0;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;

};

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout  << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
};

void 	Account::makeDeposit(int deposit) 
{
	_nbDeposits++;
	_displayTimestamp();
	std::cout <<" index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount 				+= deposit;
	_totalAmount 			+= deposit;
	_totalNbDeposits++;
};

bool 	Account::makeWithdrawal(int withdrawal) 
{
	_displayTimestamp();
	if (_amount - withdrawal < 0)
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused" << std::endl;
	else
	{
		_totalNbWithdrawals++;
		_nbWithdrawals++;
		_totalAmount 		-= withdrawal;
		std::cout  << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" <<  _nbWithdrawals << std::endl;
		_amount 			-= withdrawal;
		return (true);
	}
	return (false);
};

int 	Account::checkAmount(void) const
{
	return (1);
};

void 	Account::displayStatus(void) const 
{
	_displayTimestamp();
	std::cout  << " index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;		
};

int		Account::getNbAccounts(void) 
{
	return (_nbAccounts);
};

int		Account::getTotalAmount(void)
{
	return (_totalAmount);
};

int		Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};

int		Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;		
};

void	Account::_displayTimestamp(void)
{
	time_t		current_time = time(NULL);
	struct tm	*local_t = localtime(&current_time);
	char		time_str[32];

	strftime(time_str, sizeof(time_str), "[%Y%m%d_%H%M%S]", local_t);
	std::cout << time_str;
};
