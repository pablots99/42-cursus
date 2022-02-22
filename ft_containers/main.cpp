/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/22 23:27:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
// #include <./srcs/stack.hpp>
#include "srcs/iterators/iterator.hpp"
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
int main()
{
	// std::vector<int> const v(5);
	// std::vector<int>::iterator it = v.begin();
	const int size = 5;
	ft::vector<int> const fv(size);
	ft::vector<int>::iterator fit = fv.begin();



	// std::iterator_traits<ft::vector<int>::iterator> a;
	// std::iterator_traits<std::vector<int>::iterator> b;





	return 0;
}
