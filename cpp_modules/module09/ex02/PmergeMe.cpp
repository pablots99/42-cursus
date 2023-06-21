/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:39:25 by pablo             #+#    #+#             */
/*   Updated: 2023/06/20 19:57:01 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** args):_args(args)
{
  _readArgs();
  _sortVec();
  _sortList();
  _printVec();
  _printList();
}

void PmergeMe::_sortVec() {
  
  
}

void PmergeMe::_readArgs(){
  int number;
  for (int i = 0; _args[i]; i++)
  { 
    try
    {
      number = std::atoi(_args[i]),
      _vec.push_back(number);
      _list.push_back(number);
    }
    catch(...)
    {
     std::cout << "Error: invalid number" << std::endl;
    }
  }
}

PmergeMe::~PmergeMe()
{
  
}
