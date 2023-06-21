/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:39:25 by pablo             #+#    #+#             */
/*   Updated: 2023/06/21 20:56:51 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char** args):_args(args)
{
  _readArgs();
  _sortVec();
  //_sortList();
  _printVec();
  //_printList();
}

//Insertion sort
void PmergeMe::_sortVecpairs()
{
  int n = std::distance(_vec.begin(), _vec.end());
  for(int i = 1; i < n - 1;  i+=2)
  {
    
    for (int j = i - 2; i > 1; i-=2)
    if (*it > *(it + 2))
    {
      std::iter_swap(it, it + 2);
      std::iter_swap(it + 1, it + 3);
    }
  }
  _sortVecpairs(it + 2);
}

void PmergeMe::_sortVec() {
  bool is_odd = std::distance(_vec.begin(), _vec.end()) % 2 != 0;
  int last = 0;
  if (is_odd)
    last = *(_vec.end() - 1);
  
  Vecit it;
  it = _vec.begin();
  // Create pairs
  while((it != _vec.end() && it != (_vec.end() - 1))) { 
    if (*it > *(it + 1))
      std::iter_swap(it, it + 1);
    it+=2;
  }
  _printVec();
  _sortVecpairs(_vec.begin(), std::distance(_vec.begin(), _vec.end()));
}

void PmergeMe::_printVec()
{
  Vecit it;
  for(it = _vec.begin(); it != _vec.end(); it++)
    std::cout << *it << ", ";
  std::cout << std::endl;
}

void PmergeMe::_readArgs(){
  int number;
  for (int i = 1; _args[i]; i++)
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
