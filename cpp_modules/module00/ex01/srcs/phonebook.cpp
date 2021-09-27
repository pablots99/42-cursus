/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:35:18 by pablo             #+#    #+#             */
/*   Updated: 2021/09/21 13:42:51 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "phonebook.class.hpp"

using  namespace std;


Phonebook::Phonebook()
{
	this->count = 0;
}
Phonebook::~Phonebook()
{

}

bool isNumber(string str)
{

   	for (size_t i = 0; i < str.length(); i++)
	{
        if (std::isdigit(str[i]) == 0)
			return false;
    }
    return true;
}

void Phonebook::printContacts()
{
	string  index;

	cout << "     index|" << "first name|" << " last name|" << "  nickname|" << endl;
	for (size_t i = 0; i < 8; i++)
	{
		this->contacts[i].printTableContact(i);
	}
	cout << "Index of the desired entry: ";
	getline(cin,index);
	if(index.empty())
		return ;
	while(!isNumber(index) || stoi(index) >= 8)
	{
		cout << "Incorrect value" << endl;
		cout << "Index of the desired entry: ";
		getline(cin,index);
	}
	this->contacts[stoi(index)].printContact();
}

void Phonebook::add_contact()
{
	Contact contact;
	Contact aux;

	if((this->count >= 8))
	{
		this->count = 7;
		for (size_t i = 0; i < this->count; i++)
		{
			aux = this->contacts[i];
			this->contacts[i] = this->contacts[i + 1];
		}
	}
	contact.setContact();
	this->contacts[this->count] = contact;
	this->count++;
}
