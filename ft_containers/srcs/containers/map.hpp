/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:35 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/05 02:36:13 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP
#include <iostream>
#include "../utils.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../avlTree.hpp"

namespace ft
{

	template <class Key,
			  class T,
			  class Compare = std::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef value_type *pointer;
		typedef Avl<Key, T, ft::pair<Key, T> > __tree;
		typedef typename __tree::node node;
		typedef ft::TreeIterator<ft::pair<Key, T>, node> iterator;
		// add const iterator to alvtree
		typedef ft::TreeIterator<ft::pair<Key, T>, node> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<iterator> const_reverse_iterator;


		class value_compare
		{ // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
			friend class map;
		protected:
			Compare comp;
			value_compare(Compare c) : comp(c) {} // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}
		};


		/*
			constructors
		*/


		map() : _tree(__tree())
		{
		}

		explicit map(const Compare &comp, const Alloc &alloc = Alloc()) : _comp(comp), _allocator(alloc) {}

		template <class InputIt>
		map(InputIt first, InputIt last,
			const Compare &comp = Compare(),
			const Alloc &alloc = Alloc()) : _tree(__tree()), _comp(comp), _allocator(alloc)
		{
			// if is valid iterator
			_tree.insert(first, last);
		};
		map(const map &other)
		{
			_tree.clear();
			_comp = key_comp();
			_allocator = other.get_allocator();
			_tree.insert(other.begin(), other.end());
		}




		// make deep copy??
		map &operator=(const map &other)
		{
			_tree.clear();
			_comp = key_comp();
			_allocator = other.get_allocator();
			_tree.insert(other.begin(), other.end());
			return *this;
		}

		ft::pair<iterator, bool> insert(value_type const val) { return _tree.insert(val); }

		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			_tree.insert(first, last);
		}

		iterator insert(iterator position, const value_type &val)
		{
			return _tree.insert_at(position, val);
		}

		key_compare key_comp() const
		{
			return _comp;
		};

		mapped_type at(key_type const &key) { return _tree.get(key)->val->second; }

		size_type size() const { return _tree.getSize(); }

		size_type count(const key_type &k) const
		{
			if (_tree.get(k))
				return 1;
			return 0;
		}

		void clear()
		{
			_tree.clear();
		}

		iterator begin() { return _tree.begin(); }

		iterator end() { return _tree.end(); }

		const_iterator begin() const { return _tree.cbegin(); }

		const_iterator end() const { return _tree.cend(); }

		reverse_iterator rbegin() { return _tree.rbegin(); }

		reverse_iterator rend() { return _tree.rend(); }

		reverse_iterator crbegin() { return _tree.crbegin(); }

		reverse_iterator crend() { return _tree.crend(); }

		bool empty() const { return size() == 0; }

		iterator find(const key_type &k) { return _tree.find(k); }

		const_iterator find(const key_type &k) const { return _tree.find(k); }

		allocator_type get_allocator() const { return Alloc(); }

		size_type max_size() const
		{
			return _tree.max_size();
		}
		value_compare value_comp() const{
			return value_compare(_comp);
		}

		mapped_type &operator[](const key_type &k)
		{
				iterator v =  _tree.find(k);
				if(v.base())
					return v->second;
				v = insert(make_pair(k,mapped_type())).first;
				return v->second;


		}

	public:
		__tree _tree;
		Compare _comp;
		allocator_type _allocator;
	};
}
#endif
