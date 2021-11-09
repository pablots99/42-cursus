/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:45:32 by pablo             #+#    #+#             */
/*   Updated: 2021/11/09 21:27:13 by pablo            ###   ########.fr       */
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
	void (Karen::*p[4])(void);
	p[0] = &Karen::debug;
	p[1] = &Karen::info;
	p[2] = &Karen::warning;
	p[3] = &Karen::error;
	functions[0] = "DEBUG";
	functions[1] = "INFO";
	functions[2] = "WARNING";
	functions[3] = "ERROR";
	for (int i = 0; i < 4; i++) {
		if(level == functions[i])
		{
			std::cout << i << std::endl;
			while(i < 4){
				std::cout << "[" << functions[i] << "]" << std::endl;
				(karen.*p[i])();
				i++;
				std::cout << std::endl;
			}
			break ;
		}
	}
}



void Karen::debug(){
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(){
	std::cout <<  "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error() {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

Karen::~Karen()
{
}
