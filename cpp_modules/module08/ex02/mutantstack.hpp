/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:43:33 by pablo             #+#    #+#             */
/*   Updated: 2022/01/21 13:04:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
#define MUTANT_HPP

#include <iostream>
#include <stack>


template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack():std::stack<T>(){}
	MutantStack(MutantStack &obj){
		*this = obj;
	}
	~MutantStack(){}
	typedef	T*	iterator;
	T *end() {return	&this->top() + 1;}
	T *begin(){return ((&this->top() + 1) - this->size());}
};

#endif

