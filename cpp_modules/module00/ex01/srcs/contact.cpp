/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:45:30 by pablo             #+#    #+#             */
/*   Updated: 2021/09/21 13:29:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"


using namespace std;

Contact::Contact(){

}

Contact::~Contact(){

}

void Contact::printContact()
{
	if(this->_firstName.empty())
		return ;
	cout << "FIRST NAME	:  " << this->_firstName	<< endl;
	cout << "LAST NAME	:  " << this->_lastName		<< endl;
	cout << "NICK NAME	:  " << this->_nickName		<< endl;
	cout << "PHONE		:  " << this->_phone		<< endl;
	cout << "DARKEST SECRET	:  " << this->_secret		<< endl;
}

int add_spaces(string str)
{
	int len =  10 - str.length();
	while (len--)
	{
		cout << " ";
	}
	return 1;
}

void Contact::printTableContact(int i)
{
	if(this->_firstName.empty())
		return ;
	cout << "         " << i << "|";
	if(this->_firstName.length() > 10)
		cout << this->_firstName.substr(0,9) << ".|";
	else if (add_spaces(this->_firstName))
		cout << this->_firstName << "|";
	if(this->_lastName.length() > 10)
		cout << this->_lastName.substr(0,9) << ".|";
	else if (add_spaces(this->_lastName))
		cout << this->_lastName << "|";
	if(this->_nickName.length() > 10)
		cout << this->_nickName.substr(0,9) << ".|";
	else if (add_spaces(this->_nickName))
		cout << this->_nickName << "|";
	cout << endl;
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
	cout << "Fill the fields correctly!" << endl;
	cout << "FIRST NAME:";
	getline(cin, this->_firstName);
	while(this->_firstName.empty())
	{
		cout << "First name can not be empty" << endl;
		cout << "FIRST NAME:";
		getline(cin, this->_firstName);
	}
	cout << "LAST NAME:";
	getline(cin, this->_lastName);
	while(this->_lastName.empty())
	{
		cout << "Last name can not be empty" << endl;
		cout << "LAST NAME:";
		getline(cin, this->_lastName);
	}
	cout << "NICK NAME:";
	getline(cin, this->_nickName);
	while(this->_nickName.empty())
	{
		cout << "Nick name can not be empty" << endl;
		cout << "NICK NAME:";
		getline(cin, this->_nickName);
	}
	cout << "PHONE NUMBER:";
	getline(cin, this->_phone);
	while(this->_phone.empty() ||  !_isNumber(this->_phone) )
	{
		cout << "Phone number incorrect value" << endl;
		cout << "PHONE NUMBER:";
		getline(cin, this->_phone);
	}
	cout << "DARKEST SECRET:";
	getline(cin, this->_secret);
	while(this->_secret.empty())
	{
		cout << "Darkest secret can not be empty" << endl;
		cout << "DARKEST SECRET:";
		getline(cin, this->_secret);
	}
}
