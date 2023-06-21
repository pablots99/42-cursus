/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:34:11 by pablo             #+#    #+#             */
/*   Updated: 2023/06/20 19:51:46 by pablo            ###   ########.fr       */
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
  std::vector<int>  _vec;
  std::list<int>    _list;
  char**            _args;
  void _readArgs();
  void _sortList();
  void _sortVec();
  void _printVec();
  void _printList();
public:
  PmergeMe(char** args);
  ~PmergeMe();
};

#endif
