/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/03/01 03:06:25 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <stack>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
#include "srcs/iterators/iterator.hpp"
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
#include <functional>






void search_tree() {

	ft::BinarySearchTree<int, std::string>   tree;

	tree.push(1,"hola");
	tree.push(3,"aa");
	tree.push(4,"sa");
	tree.push(-1,"ssaa");
	tree.push(-3,"ssaa");
	tree.push(-2,"ssaa");
	tree.push(0,"ssaa");


	tree.print();
	tree.remove(3);
	tree.print();
	std::cout << tree.get(3) << std::endl;

}


int main()
{

	search_tree();




	return 0;
}
