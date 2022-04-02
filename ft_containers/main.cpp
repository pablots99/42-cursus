/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/02 02:19:46 by pablo            ###   ########.fr       */
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


void search_tree() {

	ft::Avl<int, std::string>   tree;
	typedef ft::Avl<int, std::string>::value_type val;
	tree.insert(val(30,"aa"));
	tree.print();
	tree.insert(val(10,"sa"));
	tree.print();
	tree.insert(val(20,"hola20"));
	tree.print();
	tree.insert(val(9,"hola"));
	tree.print();
	tree.insert(val(8,"hola88"));
	tree.print();
	tree.insert(val(7,"hola"));
	tree.print();
	tree.insert(val(40,"hola"));
	tree.print();
	tree.insert(val(41,"hola"));
	tree.print();
	tree.insert(val(6,"hola"));
	tree.print();
	// tree.remove(20);

	std::cout << "-----------------------------------------" << std::endl;
	//tree.begin();

	// tree.insert(9,"sa");
	// tree.print();
	// tree.insert(19,"sa");
	// tree.print();
	// tree.insert(21,"sa");
	// tree.print();
	// tree.insert(31,"sa");
	// tree.print();
	//std::cout << "lenl: " <<  tree.lenL(tree.getRoot()) << " lenR: " << tree.lenR(tree.getRoot()) << " balance: " << tree.getRoot()->l->getBalance() << std::endl;

}


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
	map.insert(val(30,"aa"));
	map.insert(val(40,"jeje"));
	map.insert(val(0,"asdasd"));
	map.insert(val(1,"hola"));
	map.insert(val(2,"adios"));
	map._tree.print();
	ft::map<int, std::string>::iterator it;
	for (it = map.begin(); it != map.end(); ++it)
	{
		std::cout << "key: " << it->first << "value: " << it->second <<std::endl;
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
	my_map();
	return 0;
}
