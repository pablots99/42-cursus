/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:23 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 03:47:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat *b;
	try
	{
		b = new Bureaucrat("Bureocrat b",0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	Bureaucrat *a;
	try
	{
		a = new Bureaucrat("Bureocrat a",151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
