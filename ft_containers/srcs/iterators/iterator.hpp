/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:43:34 by ptorres           #+#    #+#             */
/*   Updated: 2022/05/09 15:38:43 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ITERATOR__HPP
#define ITERATOR__HPP
#include <iostream>

namespace ft
{

    /*Base iterator class
        http://www.cplusplus.com/reference/iterator/iterator/
    */


  template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
  struct iterator {
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
  };

	template<class Iter1, class Iter2>
	size_t distance(Iter1 first, Iter2 last)
	{
		size_t res = 0;
		while(first != last)
		{
			res++;
			++first;
		}
		return res;
	}
	template <class Iterator>
struct iterator_traits {
    /*iterator category*/
    typedef typename Iterator::iterator_category iterator_category;

    /*Type of the element where iterator point*/
    typedef typename Iterator::value_type        value_type;

    /*
    A signed integral type used to represent the distance from
    one iterator to another, or the number of elements in a range.
    */
    typedef typename Iterator::difference_type   difference_type;

    /*Iterator's pointer type: a pointer to its value type.*/
    typedef typename Iterator::pointer           pointer;

    /*Iterator's reference type: a reference to its value type.*/
    typedef typename Iterator::reference         reference;
};


/*pointer implemntation */
template <class T>
struct iterator_traits<T*> {
    typedef T iterator_category;
    typedef T                          value_type;
    typedef ptrdiff_t                  difference_type;
    typedef T*                         pointer;
    typedef T&                         reference;
};


template <class T>
struct iterator_traits<const T*> {
    typedef  T iterator_category;
    typedef const T                          value_type;
    typedef  ptrdiff_t                  difference_type;
    typedef  T*                         pointer;
    typedef  T&                         reference;
  };


};

#endif
