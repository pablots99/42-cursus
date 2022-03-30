/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/03/30 04:15:41 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
#include "srcs/iterators/iterator.hpp"
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
#include <functional>
#include "./srcs/avlTree.hpp"
#include <utility>


void search_tree() {

	ft::Avl<int, std::string>   tree;

	tree.insert(30,"aa");
	tree.print();
	tree.insert(10,"sa");
	tree.print();
	tree.insert(20,"hola20");
	tree.print();
	tree.insert(9,"hola");
	tree.print();
	tree.insert(8,"hola88");
	tree.print();
	tree.insert(7,"hola");
	tree.print();
	tree.insert(40,"hola");
	tree.print();
	tree.insert(41,"hola");
	tree.print();
	tree.insert(6,"hola");
	tree.print();

	std::cout << "val: " << tree.get(8) << std::endl;


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
	m.insert( std::pair<int, std::string>(100,"hola"));
	m.insert( std::pair<int, std::string>(10,"asd"));
	m.insert( std::pair<int, std::string>(200,"jjaaj"));
	for (it = m.begin(); it != m.end(); ++it)
	{
		std::cout << "f: " << it->first << "s: " << it->second << std::endl;
	}
}


int main()
{
	search_tree();
	//righRot();
	//map_iterator();
	return 0;
}
