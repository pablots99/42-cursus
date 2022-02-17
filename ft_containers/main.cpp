/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:34:36 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/17 17:20:43 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <map>
#include <vector>
// #include "./srcs/map.hpp"
#include "./srcs/containers/vector.hpp"
// #include <./srcs/stack.hpp>
#include "srcs/iterators/reverse_iterator.hpp"
#include <iterator>
int main()
{
	ft::vector<int> v;
  ft::vector<int> v1;

  v.assign(7,200);
  v.assign (7,100);             // 7 ints with a value of 100
  ft::vector<int>::iterator it;
  

  v.insert(v.begin() + 4,123);

  for ( it = v.begin(); it != v.end(); ++it)
      std::cout << *it << ", ";
  
  std::cout << std::endl;

  v.insert(v.begin() +5, 5,222);



  for ( it = v.begin(); it != v.end(); ++it)
      std::cout << *it << ", ";
  

  std::cout << std::endl << "size: " << v.size() << std::endl;
  std::cout << "capacity: " << v.capacity() << std::endl;


  return 0;
}
