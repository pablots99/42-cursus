/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:31:56 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/21 11:50:10 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CPP
#define SPAN_CPP

#include <iostream>
#include <vector>

class Span {

	class OutOfIndexException : public std::exception {
			 const char * what() const throw() {
				return "Out of index exception";
			}
	};
	class NoPosibleSpanException : public std::exception
	{
		char const * what() const throw()
		{
			return "No Posible Span";
		}
	};
    private:
        const unsigned int _N;
        std::vector<int>  _nums;
    public:
        Span(unsigned int n);
		Span(Span const &obj);
		Span &operator=(Span &obj);
		~Span();
		void addNumber(unsigned const int n);
		void addRange(std::vector<int>::iterator t1,std::vector<int>::iterator t2);
		int getN();
		int shortestSpan();
		int longestSpan();
};

#endif
