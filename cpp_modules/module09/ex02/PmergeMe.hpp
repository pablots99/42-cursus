/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:34:11 by pablo             #+#    #+#             */
/*   Updated: 2023/06/21 20:56:23 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <list>
#include <iostream>
#include <vector>

class PmergeMe
{
private:
  typedef  std::vector<int>::iterator  Vecit;
  typedef  std::vector<int>::iterator  Listit;
  std::vector<int>  _vec;
  std::list<int>    _list;
  char**            _args;
  void _readArgs();
  void _printVec();
  void _sortVec();
  void _sortVecpairs();
  //void _printList();
  //void _sortList();
  //void _printList();
public:
  PmergeMe(char** args);
  ~PmergeMe();
};

#endif
