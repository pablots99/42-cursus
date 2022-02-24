/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/24 16:48:43 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <stack>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
#include <./srcs/stack.hpp>
#include "srcs/iterators/iterator.hpp"
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
int main()
{
	// std::vector<int> v(5);
	// std::vector<int>::iterator it = v.begin();
	std::deque<int> v(5);
	
	std::stack<int> stack(v);



	// std::iterator_traits<ft::vector<int>::iterator> a;
	// std::iterator_traits<std::vector<int>::iterator> b;





	return 0;
}
