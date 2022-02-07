/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:43:34 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/07 18:12:41 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

#include "iterator_traits.hpp"

namespace ft
{

    /*Iterator categorys tags is not ideal to use it*/
    struct input_iterator_tag { };

    struct output_iterator_tag { };

    struct forward_iterator_tag : public input_iterator_tag { };

    struct bidirectional_iterator_tag : public forward_iterator_tag { };

    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

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

    /*Input iterator */
     
 
    /*Forward iterator*/


    /*Reverse iterator*/


};

#endif