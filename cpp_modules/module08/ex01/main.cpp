/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:30:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/21 12:36:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <vector>

int main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << "add range " << std::endl;
	static const int arr[] = {100,16,2,77,29};
	std::vector<int> vect  (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	Span sp2(vect.size());
	std::cout << "length: " << sp2.getN() << std::endl;
	sp2.addRange(vect.begin(),vect.end());
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
}
