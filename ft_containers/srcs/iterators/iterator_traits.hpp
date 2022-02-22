/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:30:41 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/22 12:33:48 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

#include <iostream>
#include "iterator.hpp"


namespace ft {

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
