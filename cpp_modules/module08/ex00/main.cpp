/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:16:34 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/20 23:02:01 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> l;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    std::list<int>::iterator it;

    for (it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

	std::cout << "search iterator..." << std::endl;
	try
	{
		std::cout << *easyfind(l,10) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *easyfind(l,3) << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}



}
