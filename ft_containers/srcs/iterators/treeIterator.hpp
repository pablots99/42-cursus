/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeIterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 20:04:28 by ptorres           #+#    #+#             */
/*   Updated: 2022/03/03 20:39:15 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TREE_ITER_HPP
#define TREE_ITER_HPP

#include "iterator.hpp"
#include <iterator>


namespace ft {


    template <class Iter>
    class TreeIterator: public ft::iterator<std::bidirectional_iterator_tag, Iter>
    {
        	/* iterator traits*/
    
		    /******************/
    };



};


#endif