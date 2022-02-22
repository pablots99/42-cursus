/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:23 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 13:34:05 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b;
	Bureaucrat *a;
	Bureaucrat *c;
	try
	{
		b = new Bureaucrat("Bureocrat b",0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		a = new Bureaucrat("Bureocrat a",151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		c = new Bureaucrat("Bureocrat c",10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << *c  << std::endl;
}
