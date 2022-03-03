/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/03/03 20:53:09 by ptorres          ###   ########.fr       */
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
#include "./srcs/binaryTree.hpp"
#include <utility>




void search_tree() {

	ft::BinarySearchTree<int, std::string>   tree;

	tree.insert(1,"hola");
	tree.insert(6,"aa");
	tree.insert(8,"sa");
	tree.insert(-1,"ssaa");
	tree.insert(-3,"ssaa");
	tree.insert(-2,"ssaa");
	tree.insert(0,"ssaa");
	tree.insert(-4,"ssaa");
	tree.insert(10,"ssaa");
	tree.insert(7,"ssaa");


	tree.print();
	std::cout << "Max: "<<  tree.getMax()->getKey() << std::endl;
	tree.removeKey(1);
	tree.print();
	// std::cout << tree.get(3) << std::endl;

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

	//search_tree();
	map_iterator();



	return 0;
}
