/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:34:11 by pablo             #+#    #+#             */
/*   Updated: 2023/06/22 12:55:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <list>
#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <regex>
class PmergeMe
{
private:
  std::vector<int>  _vec;
  std::list<int>    _list;
  typedef std::list<int>::iterator Iterator;
  char**            _args;
  void _VectorReadArgs();
  void _ListReadArgs();
  double timeVec;
  double timeList;
  void _ListInsertion(Iterator begin, Iterator end);
  void _VecInsertion(int begin, int end);
  void _VecMerge(int begin, int end, int mid);
  void _ListMerge(Iterator begin, Iterator mid, Iterator end);
  double _ListMergeInsertSort(Iterator begin, Iterator end);
  double _VecMergeInsertSort(int begin, int end);
public:
  PmergeMe(char** args);
  PmergeMe();
  PmergeMe(PmergeMe const &src);
  PmergeMe &operator=(const PmergeMe &obj);
  ~PmergeMe();
};

template <typename T>
void print(T container);

#endif
