/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:16:47 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/21 12:16:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASY_HPP
#define EASY_HPP
#include "iostream"


class NoIteratorException : public std::exception
{
		char const * what() const throw()
		{
			return "Can not find number";
		}
};

template<typename T>
typename T::iterator easyfind(T c, int n)
{
		typename T::iterator it = std::find(c.begin(), c.end(), n);
		if(it == c.end())
		 	throw NoIteratorException();
		return it;
}




#endif
