/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:35 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/03 23:59:57 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_MAP_HPP
#define FT_MAP_HPP
#include <iostream>
#include "../utils.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../avlTree.hpp"

namespace ft {

    template < class Key,
			class T,
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
				//add const iterator to alvtree
				typedef ft::TreeIterator<ft::pair<Key,T> >		const_iterator;
				typedef ft::reverse_iterator<iterator> reverse_iterator;
				typedef ft::reverse_iterator<iterator> const_reverse_iterator;

				

				/*
					constructors
				*/

				map():_tree(__tree()){}
	
				explicit map( const Compare& comp,const Alloc& alloc = Alloc()):_comp(comp),_allocator(alloc){}
				
				template< class InputIt >
				map( InputIt first, InputIt last,
				const Compare& comp = Compare(),
				const Alloc& alloc = Alloc()):
				_tree(__tree()),_comp(comp),_allocator(alloc)
				{
					//if is valid iterator
					_tree.insert(first,last);

				};

	
				//add compare 
				// class value_compare: public ft::map<Key, T, Compare, Alloc> {

				// }
				void insert(value_type const val) { _tree.insert(val);}
	




				mapped_type at(key_type const &key){ return _tree.get(key)->val->second; }

				size_type size() const {return _tree.getSize(); }

				size_type count (const key_type& k) const {
					if(_tree.get(k))
						return 1;
					return 0;
				}

				void clear() {
					_tree.clear();
				}

				iterator begin()  { return _tree.begin(); }

				iterator end() { return _tree.end(); }

				const_iterator begin() const{  return _tree.cbegin();}

				const_iterator end()  const{ return _tree.cend(); }

				reverse_iterator rbegin() { return _tree.rbegin(); }

				reverse_iterator rend() { return _tree.rend(); }

				reverse_iterator crbegin() { return _tree.crbegin(); }

				reverse_iterator crend() { return _tree.crend(); }

				bool empty() const {return size() == 0; }

				iterator find (const key_type& k) { return iterator(_tree.find(k)); }

				const_iterator find (const key_type& k) const {return const_iterator(_tree.find(k)); }

				allocator_type get_allocator() const {return Alloc(); }

				size_type max_size() const {
					return _allocator.max_size();
				}

			public:
				__tree   		_tree;
				Compare 		_comp;
				allocator_type	_allocator;

	};
}
#endif
