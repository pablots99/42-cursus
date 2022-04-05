/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/05 19:52:23 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
#include "./srcs/containers/map.hpp"
#include "srcs/iterators/iterator.hpp"
#include <iterator>
#include <functional>
#include "./srcs/avlTree.hpp"
#include <utility>
#include "srcs/utils.hpp"
#include <list>
void map_iterator() {

	std::map<int,std::string> m;
	std::map<int, std::string>::iterator it;
	for (size_t i = 0; i < 100; i++)
	{
		m.insert( std::pair<int, std::string>(i,"hola"));

	}
	for (size_t i = 200; i > 100; i--)
	{
		m.insert( std::pair<int, std::string>(i,"hola"));

	}

	for (it = m.begin(); it != m.end(); ++it)
	{
		std::cout << "f: " << it->first << ", ";
	}
	std::cout << std::endl;
}


void my_map() {
	ft::map<int, std::string> map;
	typedef ft::Avl<int, std::string>::value_type val;
	map.insert(ft::make_pair(30,"aa"));
	map.insert(ft::make_pair(40,"jeje"));
	map.insert(ft::make_pair(0,"asdasd"));
	map.insert(ft::make_pair(1,"hola"));
	map.insert(ft::make_pair(2,"adios"));
	// map._tree.print();
	ft::map<int, std::string>::iterator it = map.begin();
	ft::map<int, std::string>::iterator ite = map.end();

	while (it != ite) {
		std::cout << "-> " << it->first << ", " << it->second << std::endl;
				it++;

	}

}

#define T1 char
#define T2 int
typedef ft::pair<const char, int> T3;
typedef std::pair<const char, int> T4;

void empty() {
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));

	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::iterator it = mp.begin();
	mp._tree.print();
	for(size_t i =0 ; it != mp.end(); ++it,i++) {
				std::cout << "-> " << it->first << ", " << it->second << std::endl;
	}
		std::cout << "-> rev"<< std::endl;
	it = mp.end();
	for(size_t i= 0 ; it != mp.begin() && i < 10 ;i++ ) {
				--it;
				std::cout << "-> " << it->first << ", " << it->second << std::endl;
	}
}

void ritermap() { 
	std::list<T4> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T4('a' + i, lst_size - i));
	std::map<T1, T2> mp(lst.begin(), lst.end());
	std::map<T1, T2>::reverse_iterator it = mp.rbegin();
	//mp._tree.print();
	std::cout << "-> " << it->first << ", " << it->second << std::endl;
	for(size_t i =0 ; it != mp.rend();it++,i++) {
				std::cout << "-> " << it->first << ", " << it->second << std::endl;
	}
}
void ritermap2() { 
	std::list<T3> lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3('a' + i, lst_size - i));
	ft::map<T1, T2> mp(lst.begin(), lst.end());
	ft::map<T1, T2>::reverse_iterator it = mp.rbegin();
	//mp._tree.print();
	for(size_t i =0 ; it != mp.rend();it++,i++) {
				std::cout << "-> " << it->first << ", " << it->second << std::endl;
	}
}


void vector() {
	ft::vector<int> v(10,10);
	ft::vector<int>::iterator it = v.begin();
	it.base();


}

int main()
{
	//search_tree();
	//righRot();
	map_iterator();
	//my_map();
	//empty();
	//ritermap();
	//ritermap2();
	return 0;
}
