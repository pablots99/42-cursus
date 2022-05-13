/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/05/13 15:49:24 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include "../../containers/vector.hpp"
#include "../../containers/map.hpp"
#include <functional>
#include <utility>
#include <list>
#include <chrono>

// int ft_map_time() {
// 	int total = 0;
// 	int aux = 0;
// 	ft::map<int,std::string> m;
// 	ft::map<int, std::string>::iterator it;
// 	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
// 	std::chrono::steady_clock::time_point end;
// 	begin = std::chrono::steady_clock::now();
// 	for (size_t i = 0; i < 1000000; i++)
// 	{

// 		m.insert( ft::pair<int, std::string>(i,"hola" + std::to_string(i)));
// 	}
// 	for (size_t i = -1; i > -1000000; i--)
// 	{
// 		m.insert( ft::pair<int, std::string>(i,"hola" + std::to_string(i)));

// 	}
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux,
// 	std::cout << "ft insert  time = " << aux << "[ns]" << std::endl;
// 	begin = std::chrono::steady_clock::now();

// 	for (it = m.begin(); it != m.end(); ++it)
// 	{
// 		*it;
// 	}
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux;
// 	std::cout << "ft iter time  time = " << aux << "[ns]" << std::endl;
// 	begin = std::chrono::steady_clock::now();
// 	m.find(500000), m.find(500000);
// 	m.find(-500000), m.find(-500000);
// 	m.find(999999), m.find(999999);
// 	m.find(-999999), m.find(-999999);
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux;
// 	std::cout << "ft find time  time = " << aux << "[ns]" << std::endl;
// 	begin = std::chrono::steady_clock::now();
// 	m.erase(m.begin(),m.end());
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux;
// 	std::cout << "ft     erase   time = " << aux << "[ns]" << std::endl;
// 	return total;
// }


// int std_map_time() {
// 	int total = 0;
// 	int aux = 0;
// 	std::map<int,std::string> m;
// 	std::map<int, std::string>::iterator it;
// 	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
// 	std::chrono::steady_clock::time_point end;
// 	begin = std::chrono::steady_clock::now();

// 	for (size_t i = 0; i < 1000000; i++)
// 	{

// 		m.insert( std::pair<int, std::string>(i,"hola" + std::to_string(i)));
// 	}
// 	for (size_t i = -1; i > -1000000; i--)
// 	{
// 		m.insert( std::pair<int, std::string>(i,"hola" + std::to_string(i)));

// 	}
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux,
// 	std::cout << "std insert  time = " << aux << "[ns]" << std::endl;
// 	begin = std::chrono::steady_clock::now();

// 	for (it = m.begin(); it != m.end(); ++it)
// 	{
// 		*it;
// 	}
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux;
// 	std::cout << "std iter time  time = " << aux << "[ns]" << std::endl;
// 	begin = std::chrono::steady_clock::now();
// 	m.find(500000), m.find(500000);
// 	m.find(-500000), m.find(-500000);
// 	m.find(999999), m.find(999999);
// 	m.find(-999999), m.find(-999999);
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux;
// 	std::cout << "std find time  time = " << aux << "[ns]" << std::endl;
// 	begin = std::chrono::steady_clock::now();
// 	m.erase(m.begin(),m.end());
// 	end = std::chrono::steady_clock::now();
// 	aux = std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count();
// 	total +=  aux;
// 	std::cout << "std    erase   time = " << aux << "[ns]" << std::endl;
// 	return total;
// }


void leaks_map() {
	ft::map<int,std::string> m;
	ft::map<int, std::string>::iterator it;
	for (size_t i = 0; i < 10; i++)
	{
		m.insert( ft::pair<int, std::string>(i,"hola" + std::to_string(i)));
	}
	for (it = m.begin(); it != m.end(); ++it)
	{
		*it;
	}
	m.find(7);
	//m.erase(m.begin(),m.end());
	m.erase(7);
	m.erase(6);
	m.erase(5);
	m.erase(4);
	system("leaks containers");
}


void check_map() {
	std::cout << "map...";
	// int ft = ft_map_time();
	// int std =  std_map_time();
	// std::cout << "ft total: " << ft << std::endl;
	// std::cout << "std total: " << std << std::endl;
	// std::cout << "diferrence: "<<  ft / std << std::endl;
	// std::cout << "cheking leaks... "<< std::endl;
	//system("leaks containers");
}



int main()
{
	//check_map();
	leaks_map();
	return 0;
}
