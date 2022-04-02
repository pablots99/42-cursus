/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:35 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/02 02:24:05 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MAP_HPP
#define FT_MAP_HPP
#include <iostream>
#include "../utils.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../avlTree.hpp"

namespace ft {

    template < class Key,class T,
           class Compare = std::less<Key>,
           class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {

			public:
				typedef Key 					key_type;
				typedef T						mapped_type;
				typedef ft::pair<const Key, T>		value_type;
				typedef Compare					key_compare;
				typedef Alloc					allocator_type;
				typedef size_t					size_type;
				typedef std::ptrdiff_t			difference_type;
				typedef value_type 				&reference;
				typedef value_type 				*pointer;
				typedef Avl<Key, T,ft::pair<Key , T> >				__tree;
				typedef ft::TreeIterator<ft::pair<Key,T> >		iterator;

				//add compare


				// class value_compare: public ft::map<Key, T, Compare, Alloc> {

				// }
				void insert(value_type val) {
					_tree.insert(val);
				}

				T find(Key key){
					return _tree.get(key);
				}

				iterator begin() {
					return _tree.begin();
				}
				iterator end() {
					return _tree.end();
				}

			public:
				__tree   _tree;

	};
}
#endif
