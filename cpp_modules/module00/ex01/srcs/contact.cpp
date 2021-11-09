/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:45:30 by pablo             #+#    #+#             */
/*   Updated: 2021/11/01 19:49:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"



Contact::Contact(){

}

Contact::~Contact(){

}

void Contact::printContact()
{
	if(this->_firstName.empty())
		return ;
	std::cout << "FIRST NAME	:  " << this->_firstName	<< std::endl;
	std::cout << "LAST NAME	:  " << this->_lastName		<< std::endl;
	std::cout << "NICK NAME	:  " << this->_nickName		<< std::endl;
	std::cout << "PHONE		:  " << this->_phone		<< std::endl;
	std::cout << "DARKEST SECRET	:  " << this->_secret		<<std::endl;
}

int add_spaces(string str)
{
	int len =  10 - str.length();
	while (len--)
	{
		std::cout << " ";
	}
	return 1;
}

void Contact::printTableContact(int i)
{
	if(this->_firstName.empty())
		return ;
	std::cout << "         " << i << "|";
	if(this->_firstName.length() > 10)
		std::cout << this->_firstName.substr(0,9) << ".|";
	else if (add_spaces(this->_firstName))
		std::cout << this->_firstName << "|";
	if(this->_lastName.length() > 10)
		std::cout << this->_lastName.substr(0,9) << ".|";
	else if (add_spaces(this->_lastName))
		std::cout << this->_lastName << "|";
	if(this->_nickName.length() > 10)
		std::cout << this->_nickName.substr(0,9) << ".|";
	else if (add_spaces(this->_nickName))
		std::cout << this->_nickName << "|";
	std::cout << std::endl;
}

bool _isNumber(string str)
{
   	for (size_t i = 0; i < str.length(); i++)
	{
        if (std::isdigit(str[i]) == 0)
			return false;
    }
    return true;
}


void Contact::setContact()
{
	std::cout << "Fill the fields correctly!" << std::endl;
	std::cout << "FIRST NAME:";
	getline(cin, this->_firstName);
	while(this->_firstName.empty())
	{
		std::cout << "First name can not be empty" << std::endl;
		std::cout << "FIRST NAME:";
		getline(cin, this->_firstName);
	}
	std::cout << "LAST NAME:";
	getline(cin, this->_lastName);
	while(this->_lastName.empty())
	{
		std::cout << "Last name can not be empty" << std::endl;
		std::cout << "LAST NAME:";
		getline(cin, this->_lastName);
	}
	std::cout << "NICK NAME:";
	getline(cin, this->_nickName);
	while(this->_nickName.empty())
	{
		std::cout << "Nick name can not be empty" << std::endl;
		std::cout << "NICK NAME:";
		getline(cin, this->_nickName);
	}
	std::cout << "PHONE NUMBER:";
	getline(cin, this->_phone);
	while(this->_phone.empty() ||  !_isNumber(this->_phone) )
	{
		std::cout << "Phone number incorrect value" << std::endl;
		std::cout << "PHONE NUMBER:";
		getline(cin, this->_phone);
	}
	std::cout << "DARKEST SECRET:";
	getline(cin, this->_secret);
	while(this->_secret.empty())
	{
		std::cout << "Darkest secret can not be empty" << std::endl;
		std::cout << "DARKEST SECRET:";
		getline(cin, this->_secret);
	}
}
