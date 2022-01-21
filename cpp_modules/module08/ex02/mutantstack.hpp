/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 00:43:33 by pablo             #+#    #+#             */
/*   Updated: 2022/01/21 01:29:46 by pablo            ###   ########.fr       */
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
	typedef	T*	iterator;
	T *end() {return	&this->top() + 1;}
	T *begin(){return ((&this->top() + 1) - this->size());}
};

#endif

