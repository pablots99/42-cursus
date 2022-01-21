/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:31:52 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/21 14:29:02 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "span.hpp"

Span::Span(unsigned int n):_N(n)
{

}


Span & Span::operator=(Span & obj)
{
	_nums = obj._nums;
	return *this;
}

Span::Span(Span const  &obj):_N(obj._N){
	_nums = obj._nums;
}

void Span::addNumber(unsigned const int n) {

	if(_nums.size() >= _N)
		throw OutOfIndexException();
	_nums.push_back(n);
}


int Span::getN()
{
	return _N;
}

Span::~Span(){

}

void Span::addRange(std::vector<int>::iterator t1,std::vector<int>::iterator t2)
{
	while(t1 != t2)
	{
		if(_nums.size() > _N -1)
			throw OutOfIndexException();
		else 
			_nums.push_back(*t1);
		t1++;
	}
}

int Span::longestSpan() {

	if (_nums.empty() || _nums.size() < 2 )
		throw NoPosibleSpanException();
	int min = *std::min_element(_nums.begin(),_nums.end());
	int max = *std::max_element(_nums.begin(),_nums.end());
	return abs(max - min);
}

int Span::shortestSpan() {
	if (_nums.empty() || _nums.size() < 2 )
		throw NoPosibleSpanException();
	std::vector<int> aux  = _nums;
	std::vector<int>::iterator it = aux.begin();
	std::sort(aux.begin(), aux.end());
	int res = abs(*it - *(it+1));
	for (it = aux.begin() + 2; it != aux.end(); ++it)
	 		res = std::min(res,abs(*it - *(it+1)));
	return res;
}

