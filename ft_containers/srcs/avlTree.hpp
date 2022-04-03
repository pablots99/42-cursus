/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:45 by pablo             #+#    #+#             */
/*   Updated: 2022/04/04 00:01:14 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_HPP
#define FT_TREE_HPP
#include <functional>
#include "containers/stack.hpp"
#include "utils.hpp"
#include <iostream>
#include <math.h>
#include <vector>

namespace ft
{

	/*

			TREE NODE

	*/
	template <class T>
	struct Node
	{
		typedef Node<T> node;
		typedef node *pointer;
		T val;
		pointer r;
		pointer l;
		pointer parent;
		int height;
		Node(T _val) : val(_val),  r(NULL), l(NULL), parent(NULL), height(1) {}

		void updateHeight()
		{
			if (!r && !l)
			{
				height = 1;
				return;
			}
			if (r && l)
			{
				if (l->height < r->height)
					height = r->height + 1;
				else
					height = l->height + 1;
			}
			else if (l && !r)
				height = l->height + 1;
			else if (r && !l)
				height = r->height + 1;
		}
		int getBalance()
		{
			if (l && r)
				return (l->height - r->height);
			if (l)
				return l->height;
			if (r)
				return -r->height;
			return 0;
		}
		void setChildParent()
		{
			if (l)
				l->parent = this;
			if (r)
				r->parent = this;
		}
		node *getMin(node *n)
		{
			if (!n)
				n = this;
			if (!n->l)
				return n;
			return getMin(n->l);
		}
		node *getMax(node *n)
		{
			if (!n)
				n = this;
			if (!n->r)
				return n;
			return getMax(n->r);
		}
		node *next()
		{
			if (r)
				return r;

			//USE COMP!!!!!!!!!!!!!!!!!!!!!
			if(parent && val.first > parent->val.first){
				if(parent && parent->parent) {
					return parent->parent;
				}
				else
					return NULL;
			}

			return parent;
		}
		node *prev()
		{
			if (l)
				return l;

			//USE COMP!!!!!!!!!!!!!!!!!!!!!
			if(parent && val.first < parent->val.first){
				if(parent && parent->parent) {
					return parent->parent;
				}
				else
					return NULL;
			}
			return parent;
		}
	};


	/*
		NODE ITERATOR
	*/

	template <class Iter, class node = ft::Node<Iter> >
	class TreeIterator : public ft::iterator<std::bidirectional_iterator_tag, Iter>
	{
	public:
		typedef Iter iterator_type;
		typedef Iter value_type;
		typedef typename std::bidirectional_iterator_tag iterator_category;
		typedef typename ft::iterator<iterator_category, Iter>::difference_type difference_type;
		typedef typename ft::iterator<iterator_category, Iter>::pointer pointer;
		typedef node 												*node_pointer;
		typedef typename ft::iterator<iterator_category, Iter>::reference reference;
		typedef typename ft::iterator<iterator_category, const Iter>::reference const_reference;


		TreeIterator(void) : _base(NULL) {}
		TreeIterator(const node_pointer p) : _base(p) {}

		template <typename U>
		TreeIterator(const TreeIterator<U> &obj) : _base(obj.base()) {}

		reference operator*() const { return _base->val; }
		pointer operator->() const { return std::addressof(operator*()); }
		TreeIterator &operator++()
		{
			_base = _base->next();
			return *this;
		}
		TreeIterator operator++(int)
		{
			TreeIterator tmp(*this);
			++*this;
			return tmp;
		}
		TreeIterator &operator--()
		{
			_base = _base->prev();
			return *this;
		}
		TreeIterator operator--(int)
		{
			TreeIterator tmp(*this);
			--*this;
			return tmp;
		}
		node_pointer base() const {
			return _base;
		}

	private:
		node_pointer _base;
	};
	template <class Iter1, class Iter2>
	bool operator==(TreeIterator<Iter1> const &i1, TreeIterator<Iter2> const &i2) { return i1.base() == i2.base(); }

	template <class Iter1, class Iter2>
	bool operator!=(TreeIterator<Iter1> const &i1, TreeIterator<Iter2> const &i2) { return !(i1==i2); }

	/*
		ALV TREE
	*/
	template <class Key, class val, class T = ft::pair<Key, val>, typename Compare = std::less<Key> >
	class Avl
	{

	public:
		typedef T value_type;
		typedef Key key_type;
		typedef Node<T> node;
		typedef TreeIterator<T> iterator;
		typedef TreeIterator<T> const_iterator;
		Avl() : _root(NULL), _size(0), comp(Compare()) {}
		~Avl() {}

		iterator begin() { return iterator(_root->getMin(NULL)); }

		iterator end(){ return iterator(NULL); }

		const_iterator cbegin() const { return const_iterator(_root->getMin(NULL)); }

		const_iterator cend() const { return const_iterator(NULL); }

		iterator rbegin() { return iterator(_root->getMax(NULL)); }

		iterator rend() { return iterator(NULL); }

		const_iterator crbegin(){ return const_iterator(_root->getMax(NULL));}

		const_iterator crend(){ return const_iterator(NULL); }

		size_t getSize() const { return _size; }


		node* get(Key const &k)
		{
			node *res = _get(k, _root);;
			return res;
		}

		iterator find(Key const k) const {
			return iterator(get(k));
		}

		void remove(Key k)
		{
			_deleteNode(k, &_root);
		}

		iterator insert(T pair)
		{
			node *n = new node(pair);
			_size++;
			return _insert(n, &_root);
		}
		
		template< class InputIt >
		void insert(InputIt begin, InputIt end) { 
			for(; begin != end; ++begin) { 
				insert(*begin);
			}
		}

		void clear() {
			_size = 0;
			_clear(_root);
		}

	private:
		node *_root;
		size_t _size;
		Compare comp;
		// no funciona
		node *_deleteNode(Key key, node **n)
		{
			if (!(*n)->l && !(*n)->r)
			{
				// if root root == NULL?
				return NULL;
			}
			if (key == (*n)->val.first)
			{
				node *aux = *n;
				while (aux->r || aux->l)
				{
					if (aux->r)
						aux = aux->r;
					else
						aux = aux->l;
				}
				node *aux1 = aux;
				(*n)->val.first = aux->val.first;
				(*n)->value = aux->value;
				if ((*n)->r)
					(*n)->r = _deleteNode(aux->val.first, &(*n)->r);
				else
					(*n)->l = _deleteNode(aux->val.first, &(*n)->l);
			}
			else if ((*n)->l && comp(key, (*n)->val.first))
				return _deleteNode(key, &(*n)->l);
			else if ((*n)->r)
				return _deleteNode(key, &(*n)->r);

			(*n)->updateHeight();
			int balance = (*n)->getBalance();
			if (balance == 2 && (*n)->l && (*n)->l->getBalance() == 1)
				(*n) = _rotLL((*n));
			else if (balance == -2 && (*n)->r && (*n)->r->getBalance() == -1)
				(*n) = _rotRR((*n));
			else if (balance == -2 && (*n)->r && (*n)->r->getBalance() == -1)
				(*n) = _rotRL((*n));
			else if (balance == 2 && (*n)->l && (*n)->l->getBalance() == -1)
				(*n) = _rotLR((*n));
			if ((*n)->l)
				(*n)->l->updateHeight();
			if ((*n)->r)
				(*n)->r->updateHeight();
			(*n)->updateHeight();
			return *n;
		}

		void _clear(node *n) {
			if(n->r)
				_clear(n->r);
			if(n->l)
				_clear(n->l);
			delete n->l;
		}
		node *_get(Key key, node *n)
		{
			if (n->val.first == key)
				return n;
			else if (n->l && comp(key, n->val.first))
				return _get(key, n->l);
			else if (n->r)
				return _get(key, n->r);
			return NULL;
		}

		node *_rotLL(node *n)
		{
			if (!n->l)
				return NULL;
			std::cout << "n " << n->val.first << std::endl;
			node *a = n;
			node *aux = a->l;
			aux->parent = n->parent;
			a->l = aux->r;
			a->setChildParent();
			aux->r = a;
			aux->setChildParent();
			return aux;
		}

		node *_rotRR(node *n)
		{
			if (!n->r)
				return NULL;
			node *a = n;
			node *aux = a->r;
			aux->parent = n->parent;
			a->r = aux->l;
			a->setChildParent();
			aux->l = a;
			aux->setChildParent();
			return aux;
		}

		node *_rotRL(node *n)
		{
			if (!n->l)
				return NULL;
			node *aux = n->r;
			node *aux2 = n->r->l;
			aux2->parent = n->parent;
			n->r = aux2->l;
			n->setChildParent();
			aux->l = aux2->r;
			aux->setChildParent();
			aux2->l = n;
			aux2->r = aux;
			aux2->setChildParent();
			return aux2;
		}

		node *_rotLR(node *n)
		{
			if (!n->l)
				return NULL;
			node *aux = n->l;
			node *aux2 = n->l->r;
			aux2->parent = n->parent;
			n->l = aux2->r;
			n->setChildParent();
			aux->r = aux2->l;
			aux->setChildParent();
			aux2->r = n;
			aux2->l = aux;
			aux2->setChildParent();
			return aux2;
		}

		iterator _insert(node *n, node **curr)
		{
			node * ret =  NULL;
			if (n == NULL)
				return iterator(NULL);
			if(n->val.first == (*curr)->val.first )
				return *curr;
			if (!_root)
			{
				_root = n;
				return iterator(NULL);
			}
			if (comp(n->val.first, (*curr)->val.first))
			{
				if (!(*curr)->l)
				{
					n->parent = *curr;
					(*curr)->l = n;
					ret = n;
				}
				else
				{
					_insert(n, &(*curr)->l);
				}
			}
			else
			{
				if (!(*curr)->r)
				{
					n->parent = *curr;
					(*curr)->r = n;
					ret = n;
				}
				else
				{
					_insert(n, &(*curr)->r);
				}
			}
			(*curr)->updateHeight();
			int balance = (*curr)->getBalance();
			if (balance == 2 && (*curr)->l && (*curr)->l->getBalance() == 1)
				(*curr) = _rotLL((*curr));
			else if (balance == -2 && (*curr)->r && (*curr)->r->getBalance() == -1)
				(*curr) = _rotRR((*curr));
			else if (balance == -2 && (*curr)->r && (*curr)->r->getBalance() == -1)
				(*curr) = _rotRL((*curr));
			else if (balance == 2 && (*curr)->l && (*curr)->l->getBalance() == -1)
				(*curr) = _rotLR((*curr));
			if ((*curr)->l)
				(*curr)->l->updateHeight();
			if ((*curr)->r)
				(*curr)->r->updateHeight();
			(*curr)->updateHeight();
			return ret;
		}
		public:
		void print()
		{
			node *n = _root;
			ft::vector<node *> stk;
			size_t i = 1;
			size_t j = 0;
			size_t size = 1;
			size_t n_count = 0;
			size_t levels = 0;
			while (1)
			{
				if (stk.size() == 0)
					stk.push_back(n);
				n_count = 0;
				for (; j < size; j++)
				{
					if (stk[j])
					{
						stk.push_back(stk[j]->l);
						stk.push_back(stk[j]->r);
					}
					else
					{
						stk.push_back(NULL);
						stk.push_back(NULL);
						n_count++;
					}
				}
				if (n_count == i)
				{
					for (i = 0; i < n_count + (n_count * 2); i++)
						stk.pop_back();
					break;
				}
				levels++;
				i *= 2;
				size += i;
			}
			n_count /= 2;
			size = ((3 + 5) * n_count) / 2;
			int sp = 11 << (levels - 2); // 11 = 3 * 2 + 5
			size_t level = 1;
			j = 1;
			for (i = 0; i < stk.size(); i++)
			{

				if (i == 0)
					std::cout << std::string(size, ' ');
				if (i == j || i == 1)
				{
					size /= 2;
					std::cout << "\n\n"
							  << std::string(size, ' ');
					sp /= 2;
					level++;
					j = (j * 2) + 1;
				}
				std::string number = "N    ";
				if (stk[i])
				{
					if (stk[i]->parent != NULL)
						number = std::to_string(stk[i]->val.first) + "," + std::to_string(stk[i]->parent->val.first);
					else
						number = std::to_string(stk[i]->val.first) + ", ()";
				}
				std::cout << number;
				if (number.length() < 5)
					std::cout << std::string(5 - number.length(), ' ');

				if (level == levels - 1)
					sp = 6;
				if (level == levels)
					sp = -2;
				std::cout << std::string(sp + 5, ' ');
			}
			std::cout << "\n\n---------------------------------------------\n";
		}
	};

};

#endif
