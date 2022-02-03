/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:29 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/01 20:08:11 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP  
#define FT_VECTOR_HPP  
#include <iostream>
#include "utils/iter.hpp"

namespace ft { 
    template<typename T>
    class vector {
        private:
            T* data;
        public::
            vector();
            T vector();
            //fill constructor Constructs a container with n elements. Each element is a copy of val.
            //range constructor Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range, in the same order.
(4) copy constructor
            ft::iterator_traits iterator;
            ft::iterator_traits reverse_iterator;
            vector();

    };
}
#endif