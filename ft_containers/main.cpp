/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/16 14:01:24 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <map>
#include <vector>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
// #include <./srcs/stack.hpp>
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
int main()
{
    ft::vector<std::string> fv(10, "hola");
    ft::vector<std::string>::iterator fiter = fv.begin();
	ft::vector<std::string> fvc(fv);
	(void)fiter;
	fvc.push_back("juan");
	for (fiter = fvc.begin(); fiter != fvc.end(); ++fiter)
	{
		std::cout << *fiter << std::endl;
	}
	fvc.pop_back();
	fiter = fvc.begin() + 3;
	fvc.insert(fiter,"dsdfjnsldfn");
	std::cout << "------------" << std::endl;
	for (fiter = fvc.begin(); fiter != fvc.end(); ++fiter)
	{
		std::cout << *fiter << std::endl;
	}

}
