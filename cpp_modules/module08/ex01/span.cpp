/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:31:52 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/21 00:31:28 by pablo            ###   ########.fr       */
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
	std::vector<int>::iterator it = _nums.begin();
	int res = abs(*it - *(it+1));
	it += 2;
	for (it = _nums.begin() + 2; it != _nums.end(); ++it)
	{
		if(abs(*it - *(it+1)) < res)
			res = abs(*it - *(it+1));
	}
	return res;
}


