/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/03/22 17:34:54 by ptorres          ###   ########.fr       */
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
	tree.insert(10,"sa");
	tree.insert(20,"hola");
	tree.insert(9,"sa");
	tree.insert(19,"sa");
	tree.insert(21,"sa");
	tree.insert(31,"sa");
	tree.print();
	std::cout << "lenl: " <<  tree.lenL(tree.getRoot()) << " lenR: " << tree.lenR(tree.getRoot()) << " balance: " << tree.getRoot()->l->getBalance() << std::endl;

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
