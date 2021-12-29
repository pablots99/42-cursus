/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:45:32 by pablo             #+#    #+#             */
/*   Updated: 2021/12/28 18:39:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <cstring>
Karen::Karen()
{
}

void Karen::filter(std::string level)
{
	Karen karen;
	std::string functions[4];
	int cont;

	cont  = 0;
	functions[0] = "DEBUG";
	functions[1] = "INFO";
	functions[2] = "WARNING";
	functions[3] = "ERROR";
	for (int i = 0; i < 4; i++) {
		if(level == functions[i])
		{
			switch (i) {
				case 0:
					karen.debug(), karen.info(),karen.warning(), karen.error();
					break ;
				case 1:
					karen.info(),karen.warning(), karen.error();
					break ;
				case 2:
					karen.warning(), karen.error();
					break ;
				case 3:
					karen.error();
					break ;
				default :
					break ;
			}
			cont = 1;
			break ;
		}
	}
	if(cont == 0)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}



void Karen::debug(){
	std::cout << "["<< "DEBUG" << "]" << std::endl;
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl << std::endl;
}

void Karen::info(){
	std::cout << "["<< "INFO" << "]" << std::endl;
	std::cout <<  "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl << std::endl;
}

void Karen::warning(){
	std::cout << "["<< "WARNING" << "]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl << std::endl;
}

void Karen::error() {
	std::cout << "["<< "ERROR" << "]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl << std::endl;
}

Karen::~Karen()
{
}
