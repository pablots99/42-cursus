/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:35 by ptorres           #+#    #+#             */
/*   Updated: 2022/05/13 00:55:06 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_HPP
#define FT_MAP_HPP
#include <iostream>
#include "../utils.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/avlTree.hpp"
#include "vector.hpp"
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
		typedef Avl<Key, T, ft::pair<Key, T>, Compare, Alloc> __tree;
		typedef typename __tree::node node;
		typedef typename __tree::iterator iterator;
		typedef typename __tree::const_iterator  const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


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
			member funcitons
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
		virtual ~map() {};

		map &operator=(const map &other)
		{
			_tree.clear();
			_comp = key_comp();
			_allocator = other.get_allocator();
			_tree.insert(other.begin(), other.end());
			return *this;
		}

		allocator_type get_allocator() const { return Alloc(); }

		/*

			element acces

		*/

		mapped_type &operator[](const key_type &k)
		{
				iterator v =  _tree.find(k);
				if(v.base())
					return v->second;
				v = insert(ft::make_pair(k,mapped_type())).first;
				return v->second;

		}

		mapped_type at(key_type const &key) { return _tree.get(key)->val->second; }


		/*

			modifiers

		*/


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

		void clear()
		{
			_tree.clear();
		}


		size_type erase( const Key& key ) {
			size_t aux = size();
			_tree.remove(key);
			return aux != size();
		}


		void erase( iterator pos )
		{
			_tree.remove(pos);
			(void)pos;
		}


		void erase( iterator first, iterator last )
		{

			ft::vector<Key> keys;
			while (first != last) {
				keys.push_back(first->first);
				++first;
			}
			typename ft::vector<Key>::iterator it;

			for(it = keys.begin() ; it != keys.end(); ++it)
			{
				erase(*it);
			}
		}
		void swap (map& x)
		{
			allocator_type auxalloc = x._allocator;
			Compare  auxcomp = x._comp;
			__tree auxtree = x._tree;

			x._allocator = _allocator;
			x._comp = _comp;
			x._tree = _tree;

			_allocator = auxalloc;
			_comp = auxcomp;
			_tree = auxtree;
		}



		/*

			capacity

		*/


		size_type size() const { return _tree.getSize(); }


		bool empty() const { return size() == 0; }


		size_type max_size() const { return _tree.max_size(); }


		/*

			lookup

		*/
		size_type count(const key_type &k) const
		{
			if (_tree.get(k))
				return 1;
			return 0;
		}


		iterator find(const key_type &k) { return _tree.find(k); }

		const_iterator find(const key_type &k) const { return _tree.find(k); }


		iterator upper_bound( const Key& key )
		{
			return _tree.get_upper_iter(key);
		}

		const_iterator upper_bound( const Key& key ) const
		{
			return _tree.get_upper_iter(key);
		}

		iterator lower_bound( const Key& key ) {
			return _tree.get_lower_iter(key);
		}

		const_iterator lower_bound( const Key& key ) const{
			return _tree.get_lower_iter(key);
		}

		ft::pair<iterator,iterator> equal_range( const Key& key ){
			return ft::make_pair(lower_bound(key),upper_bound(key));
		}
		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			return ft::make_pair(lower_bound(key),upper_bound(key));

		}

		/*

			observers

		*/

		value_compare value_comp() const{
			return value_compare(_comp);
		}

		key_compare key_comp() const
		{
			return _comp;
		}

		/*
			iterator
		*/
		iterator begin()  { return _tree.begin(); }

		iterator end() { return _tree.end(); }

		const_iterator begin() const { return _tree.cbegin(); }

		const_iterator end() const { return _tree.cend(); }

		reverse_iterator rbegin() { return reverse_iterator(_tree.rbegin()); }

		reverse_iterator rend() { return reverse_iterator(_tree.rend()); }

		const_reverse_iterator crbegin() { return const_reverse_iterator(_tree.crbegin()); }

		const_reverse_iterator crend() { return const_reverse_iterator(_tree.crend()); }



__tree _tree;
	protected:

		Compare _comp;
		allocator_type _allocator;
	};


	/*swap*/

	template <class Key, class T, class Compare, class Alloc>
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		size_t size = lhs.size();

		if(size != rhs.size())
			return false;
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it1 = lhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it2 = rhs.begin();
		typename ft::map<Key,T,Compare,Alloc>::const_iterator it_end = lhs.end();
		while(it1 != it_end)
		{
			if(*it1 != *it2)
				return false;
			++it1;
			++it2;
		}
		return true;
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end ());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return (rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs > rhs);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
	{
		return !(lhs < rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
 	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}

}
#endif
