/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:43:12 by pablo             #+#    #+#             */
/*   Updated: 2022/01/21 12:11:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <list>
int main()
{
	std::cout << "mutant -----------------"<< std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top" << mstack.top() << std::endl;
	mstack.pop();
	std::cout <<  "size" << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "long stack test!" << std::endl;
	MutantStack<int> stk;
	for (size_t i = 0; i < 1000; i++)
	{	
		stk.push(i);
	}
	it = stk.begin();
	ite = stk.end();
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
	}
	std::cout<< std::endl << "----------------------------------" << std::endl;
	std::cout<< "pop half" << std::endl;
	std::cout<< std::endl << "----------------------------------" << std::endl;
	for (size_t i = 0; i < 500; i++)
	{	
		stk.top();
		stk.pop();
	}
	it = stk.begin();
	ite = stk.end();
	while (it != ite)
	{
		std::cout << *it << ", ";
		++it;
	}
	return 0;
}
