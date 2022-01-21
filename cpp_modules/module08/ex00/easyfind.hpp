/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:16:47 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/20 23:00:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASY_HPP
#define EASY_HPP
#include "iostream"


class NoIteratorException : public std::exception
{
		char const * what() const throw()
		{
			return "No iterator found";
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
