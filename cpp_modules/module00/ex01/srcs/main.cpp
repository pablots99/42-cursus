/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:35:18 by pablo             #+#    #+#             */
/*   Updated: 2021/09/21 12:18:48 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "contact.class.hpp"
#include "phonebook.class.hpp"


using  namespace std;

int main()
{
	Phonebook agenda;
	string buff;
	while (1)
	{
		cout << ">> ";
		getline(cin, buff);
		if(buff == "EXIT")
			break ;
		else if(buff == "ADD")
			agenda.add_contact();
		else if(buff == "SEARCH")
			agenda.printContacts();

	}
	return (0);
}
