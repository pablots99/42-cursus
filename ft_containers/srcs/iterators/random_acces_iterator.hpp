/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_acces_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:17:31 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/08 19:35:29 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef random_iterator_hpp
#define random_iterator_hpp

#include "iterator.hpp"

namespace ft {


    template <typename Iter>
    struct my_random_acces_iterator { 
        typedef ft::random_access_iterator_tag iterator_category;

    
    
    };
};


#endif