/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:29 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/08 20:36:39 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP  
#define FT_VECTOR_HPP  
#include <iostream>
#include "../iterators/iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"


namespace ft { 
    template<class T, class Allocator = std::allocator<T> >
    class vector {
        private:
              typedef Allocator                                                      _allocator_type;
        public:
            typedef T                                                               value_type;
            typedef Allocator                                                       allocator_type;
            /*allocator*/
            typedef value_type&                                                     reference;
            typedef const value_type&                                               const_reference;
            typedef allocator_type::pointer                                         pointer;
            typedef const allocator_type::pointer                                   const_pointer;
            typedef const allocator_type::difference_type                           difference_type;
            /*vectory iterators*/
            typedef ft::my_random_acces_iterator<value_type>                        iterator;
            typedef ft::my_random_acces_iterator<cosnt value_type>                  const_iterator;
            typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
            typedef ft::reverse_iterator<const iterator>                            const_reverse_iterator;
    };
}
#endif
