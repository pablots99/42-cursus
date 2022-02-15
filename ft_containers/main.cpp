/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/15 20:27:38 by pablo            ###   ########.fr       */
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
	std::cout << "------------" << std::endl;
	for (fiter = fvc.begin(); fiter != fvc.end(); ++fiter)
	{
		std::cout << *fiter << std::endl;
	}

}
