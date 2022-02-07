/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/07 19:50:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <map>
#include <vector>
// #include "./srcs/map.hpp"
// #include "./srcs/vector.hpp"
// #include <./srcs/stack.hpp>
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
int main()
{ 

    std::vector<std::string> v;

 

    v.push_back("hola");
    v.push_back("hola1");
    v.push_back("hola2");


    std::vector<std::string>::iterator iter = v.begin();
    std::vector<std::string>::reverse_iterator r_iter =  v.rbegin();
    ft::reverse_iterator<std::vector<std::string>::iterator>  ri =   ft::reverse_iterator<std::vector<std::string>::iterator>(v.end());
    ri++;
    std::cout << *ri << std::endl;
    ft::reverse_iterator<std::vector<std::string>::iterator>  *rip = &ri;
    std::cout << *--rip->base() << std::endl;


    std::cout << *iter << std::endl;
    std::cout << *r_iter << std::endl;
}
