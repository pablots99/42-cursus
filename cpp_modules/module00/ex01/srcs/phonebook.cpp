/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:35:18 by pablo             #+#    #+#             */
/*   Updated: 2021/12/20 14:36:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "phonebook.class.hpp"



Phonebook::Phonebook()
{
	this->count = 0;
}
Phonebook::~Phonebook()
{

}

bool isNumber(std::string str)
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
	std::string  index;

	std::cout << "     index|" << "first name|" << " last name|" << "  nickname|" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		this->contacts[i].printTableContact(i);
	}
	std::cout << "Index of the desired entry: ";
	getline(std::cin,index);
	if(index.empty())
		return ;
	while(!isNumber(index) || stoi(index) >= 8)
	{
		std::cout << "Incorrect value" << std::endl;
		std::cout << "Index of the desired entry: ";
		getline(std::cin,index);
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
		for (int i = 0; i < this->count; i++)
		{
			aux = this->contacts[i];
			this->contacts[i] = this->contacts[i + 1];
		}
	}
	contact.setContact();
	this->contacts[this->count] = contact;
	this->count++;
}
