/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:46:52 by pablo             #+#    #+#             */
/*   Updated: 2021/11/01 22:44:08 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::~Account( void ){
	//[19920104_091532] index:7;amount:8942;closed
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
	//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
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
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
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

	//[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	if(this->_amount < withdrawal) {
		//> [19920104_091532] index:0;p_amount:47;withdrawal:refused
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



void	Account::_displayTimestamp( void ){
	std::cout << "[19920104_091532] ";
}

