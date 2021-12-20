/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:35:18 by pablo             #+#    #+#             */
/*   Updated: 2021/12/20 16:20:50 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "contact.class.hpp"
#include "phonebook.class.hpp"



int main()
{
	Phonebook agenda;
	std::string buff;
	while (1)
	{
		std::cout << ">> ";
		getline(std::cin, buff);
		if(buff == "EXIT")
			break ;
		else if(buff == "ADD")
			agenda.add_contact();
		else if(buff == "SEARCH")
			agenda.printContacts();

	}
	return (0);
}
