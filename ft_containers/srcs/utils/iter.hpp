/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:30:41 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/01 20:05:24 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATORS_HPP

#include <iostream>
#include <iterator>

namespace ft {

template <class Iterator>
  struct iterator_traits {
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type        value_type;
    typedef typename Iterator::difference_type   difference_type;
    typedef typename Iterator::pointer           pointer;
    typedef typename Iterator::reference         reference;
};

template <class T>
struct iterator_traits<T*> {
    typedef random_access_iterator_tag iterator_category;
    typedef T                          value_type;
    typedef ptrdiff_t                  difference_type;
    typedef T*                         pointer;
    typedef T&                         reference;
  };
template <class T>
struct iterator_traits<const T*> {
    typedef const random_access_iterator_tag iterator_category;
    typedef const T                          value_type;
    typedef const ptrdiff_t                  difference_type;
    typedef const T*                         pointer;
    typedef const T&                         reference;
  };


};
//falta const

#endif