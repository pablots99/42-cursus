/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:39:25 by pablo             #+#    #+#             */
/*   Updated: 2023/06/22 12:56:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **args) : _args(args)
{
  _VectorReadArgs();
  _ListReadArgs();
  std::cout << "Before: ";
  print(_vec);
  timeVec = _VecMergeInsertSort(0, _vec.size());
  timeList = _ListMergeInsertSort(_list.begin(), _list.end());
  std::cout << "After: ";
  print(_list);
  std::cout << std::fixed << std::setprecision(10);
  std::cout << "Time to process a range of " << _vec.size() << " with std::vector => " << timeVec << " s" << std::endl;
  std::cout << "Time to process a range of " << _list.size() << " with std::list => " << timeList << " s" << std::endl;
}

bool is_valid_number(std::string number) {
  return !number.empty() && number.find_first_not_of("0123456789") == std::string::npos;
}
void PmergeMe::_ListReadArgs()
{
  int number;
  for (int i = 1; _args[i]; i++)
  {
    if (is_valid_number(std::string(_args[i])))
    {
      number = std::atoi(_args[i]),
      _list.push_back(number);
    }
    else
    {
      std::cout << "Error: invalid number" << std::endl;
      exit(1);
    }
  }
}

void PmergeMe::_VectorReadArgs()
{
  int number;
  for (int i = 1; _args[i]; i++)
  {
    if (is_valid_number(std::string(_args[i])))
    {
      number = std::atoi(_args[i]),
      _vec.push_back(number);
    }
    else
    {
      std::cout << "Error: invalid number" << std::endl;
      exit(1);
    }
  }
}

void PmergeMe::_ListInsertion(Iterator begin, Iterator end)
{
  for (Iterator i = begin; i != end; ++i)
  {
    Iterator j = i;
    while (j != begin && *j < *(--j))
      std::iter_swap(j, (++j)--);
  }
}

void PmergeMe::_VecInsertion(int begin, int end)
{
  for (int i = begin; i <= end; i++) {
        int aux = _vec[i];
        int j = i - 1;
        while (j >= begin && _vec[j] > aux) {
            _vec[j + 1] = _vec[j];
            j--;
        }
        _vec[j + 1] = aux;
    }
}

void PmergeMe::_ListMerge(Iterator begin, Iterator mid, Iterator end)
{
  std::vector<int> temp;

  Iterator i = begin;
  Iterator j = mid;
  while (i != mid && j != end)
  {
    if (*i <= *j)
    {
      temp.push_back(*i);
      ++i;
    }
    else
    {
      temp.push_back(*j);
      ++j;
    }
  }
  while (i != mid)
  {
    temp.push_back(*i);
    ++i;
  }
  while (j != end)
  {
    temp.push_back(*j);
    ++j;
  }
  std::copy(temp.begin(), temp.end(), begin);
}

void PmergeMe::_VecMerge(int begin, int end, int mid)
{
   int i = begin, j = mid + 1, k = 0;
    std::vector<int> temp(end - begin + 1);

    while (i <= mid && j <= end) {
        if (_vec[i] <= _vec[j])
            temp[k++] = _vec[i++];
        else
            temp[k++] = _vec[j++];
    }
    while (i <= mid)
        temp[k++] = _vec[i++];
    while (j <= end)
        temp[k++] = _vec[j++];
    for (i = begin; i <= end; i++)
        _vec[i] = temp[i - begin];
}

double PmergeMe::_ListMergeInsertSort(Iterator begin, Iterator end)
{
  std::clock_t t_start = std::clock();
  if (std::distance(begin, end) <= 3)
  {
    _ListInsertion(begin, end);
  }
  else
  {
    Iterator mid = begin;
    std::advance(mid, std::distance(begin, end) / 2);
    _ListMergeInsertSort(begin, mid);
    _ListMergeInsertSort(mid, end);
    _ListMerge(begin, mid, end);
  }
  std::clock_t t_end = std::clock();
  return double(t_end - t_start) / CLOCKS_PER_SEC;
}

double PmergeMe::_VecMergeInsertSort(int begin, int end) {
  std::clock_t t_start = std::clock();
  if (end - begin <= 2)
      _VecInsertion(begin, end);
  else {
      int mid = begin + (end - begin) / 2;
      _VecMergeInsertSort(begin, mid);  // sort first half
      _VecMergeInsertSort(mid + 1, end);  // sort second half
      _VecMerge(begin, end, mid);  // merge sorted halves
  }
  std::clock_t t_end = std::clock();
  return double(t_end - t_start) / CLOCKS_PER_SEC;
}

template <typename T>
void print(T container) { 
  typename T::iterator it;
  size_t counter = 0;
  for(it = container.begin(); it != container.end() && counter < 6; it++)
    std::cout << *it << " ", counter++;
  if (it != container.end())
    std::cout << "[...]";
  std::cout << std::endl;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &obj)
{
	*this = obj;
	return ;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &obj)
{
	this->_vec = obj._vec;
  this->_list = obj._list;
  this->_args = obj._args;
  this->timeVec = obj.timeVec;
  this->timeList = obj.timeList;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}
