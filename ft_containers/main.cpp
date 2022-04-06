/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/06 17:19:10 by pablo            ###   ########.fr       */
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
#include "./srcs/iterators/avlTree.hpp"
#include <utility>
#include "srcs/utils.hpp"
#include <list>
#include <chrono>

void ft_map_time() {

	ft::map<int,std::string> m;
	ft::map<int, std::string>::iterator it;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;

	for (size_t i = 0; i < 1000000; i++)
	{

		m.insert( ft::pair<int, std::string>(i,"hola" + std::to_string(i)));
	}
	for (size_t i = -1; i > -1000000; i--)
	{
		m.insert( ft::pair<int, std::string>(i,"hola" + std::to_string(i)));

	}
	end = std::chrono::steady_clock::now();
	std::cout << "ft  insert  time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	begin = std::chrono::steady_clock::now();

	for (it = m.begin(); it != m.end(); ++it)
	{
		*it;
	}
	end = std::chrono::steady_clock::now();
	std::cout << "ft  iter time  time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	begin = std::chrono::steady_clock::now();
	std::cout << "finded: " << m.find(500000)->first << ":" <<  m.find(500000)->second;
	std::cout << "finded: " << m.find(-500000)->first << ":" <<  m.find(-500000)->second;
	std::cout << "finded: " << m.find(999999)->first << ":" <<  m.find(999999)->second;
	std::cout << "finded: " << m.find(-999999)->first << ":" <<  m.find(-999999)->second;
	std::cout << std::endl;
	end = std::chrono::steady_clock::now();
	std::cout << "ft  find time  time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

}
void std_map_time() {

	std::map<int,std::string> m;
	std::map<int, std::string>::iterator it;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end;

	for (size_t i = 0; i < 1000000; i++)
	{

		m.insert( std::pair<int, std::string>(i,"hola" + std::to_string(i)));
	}
	for (size_t i = -1; i > -1000000; i--)
	{
		m.insert( std::pair<int, std::string>(i,"hola" + std::to_string(i)));

	}
	end = std::chrono::steady_clock::now();
	std::cout << "std insert  time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	begin = std::chrono::steady_clock::now();

	for (it = m.begin(); it != m.end(); ++it)
	{
		*it;
	}
	end = std::chrono::steady_clock::now();
	std::cout << "std iter time  time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
	begin = std::chrono::steady_clock::now();
	std::cout << "finded: " << m.find(500000)->first << ":" <<  m.find(500000)->second;
	std::cout << "finded: " << m.find(-500000)->first << ":" <<  m.find(-500000)->second;
	std::cout << "finded: " << m.find(999999)->first << ":" <<  m.find(999999)->second;
	std::cout << "finded: " << m.find(-999999)->first << ":" <<  m.find(-999999)->second;
	std::cout << std::endl;
	end = std::chrono::steady_clock::now();
	std::cout << "std find time  time = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

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
	//map_iterator();
	std_map_time();
	ft_map_time();
	//my_map();
	//empty();
	//ritermap();
	//ritermap2();
	return 0;
}
