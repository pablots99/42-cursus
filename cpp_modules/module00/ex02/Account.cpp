/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:46:52 by pablo             #+#    #+#             */
/*   Updated: 2022/01/04 17:21:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>
#include <ctime>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account( void ){
	this->_nbAccounts--;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}
Account::Account( int initial_deposit ) {
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout <<  "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
}

void	Account::displayAccountsInfos( void ) {
		Account::_displayTimestamp();
		std::cout << "accounts:" <<  Account::_nbAccounts;
		std::cout << ";total:" <<  Account::_totalAmount;
		std::cout << ";deposits:" <<  Account::_totalNbDeposits;
		std::cout << ";withdrawals:" <<  Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus( void ) const{
	Account::_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex;
	std::cout << ";amount:" <<  this->_amount;
	std::cout << ";deposits:" <<  this->_nbDeposits;
	std::cout << ";withdrawals:" <<  this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}


void	Account::makeDeposit( int deposit ) {
	int p_amount  = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex;
	std::cout << ";p_amount:" <<  p_amount;
	std::cout << ";deposit:" <<  deposit;
	std::cout << ";amount:" <<  this->_amount;
	std::cout << ";nb_deposits:" <<  this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	Account::_displayTimestamp();
	std::cout << "index:" <<  this->_accountIndex;
	std::cout << ";p_amount:" <<  this->_amount;
	if(this->_amount < withdrawal) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount-=withdrawal;
	std::cout << ";withdrawal:" <<  withdrawal;
	std::cout << ";amount:" <<  this->_amount;
	std::cout << ";nb_withdrawals:" <<  this->_nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void )  const{
	return Account::_amount;
}


std::string fill_zero(int num,bool date)
{
	std::string str =  std::to_string(num);
	std::string res = "0";
	if(str.length() == 1 && str[0] == '0'  && date)
		return "01";
	else if(str.length() == 1)
		return res.append(str);
	else if (str.length() == 0)
		return res.append("0");
	return (str);
}
void	Account::_displayTimestamp( void ){

	time_t now = time(0);
	tm *ltm = localtime(&now);
  	std::cout << "[" << ltm->tm_year + 1900  <<
	  	fill_zero(ltm->tm_mon, 1)  <<
		fill_zero(ltm->tm_mday, 1) <<
		"_" <<
		fill_zero(ltm->tm_hour, 0) <<
		fill_zero(ltm->tm_min, 0)  <<
		fill_zero(ltm->tm_sec, 0)  << "] ";
}

