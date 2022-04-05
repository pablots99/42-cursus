/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:45 by pablo             #+#    #+#             */
/*   Updated: 2022/04/05 02:39:36 by pablo            ###   ########.fr       */
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
	template <class T,class Compare>
	struct Node
	{
		typedef Node<T,Compare> node;
		typedef node *pointer;
		T val;
		pointer r;
		pointer l;
		pointer parent;
		int height;
		Compare comp;

		Node(Compare _comp = Compare()) : val(),  r(NULL), l(NULL), parent(NULL), height(0),comp(_comp) {}
		Node(T _val,Compare _comp = Compare()) : val(_val),  r(NULL), l(NULL), parent(NULL), height(1),comp(_comp) {}

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
			if (!n)
				return NULL;
			if (!n->l)
				return n;
			return getMin(n->l);
		}
		node *getMax(node *n)
		{
			if (!n)
				n = this;
			if (!n)
				return NULL;
			if (!n->r)
				return n;
			return getMax(n->r);
		}
		node *next()
		{
			if (r)
				return getMin(r);
			node *aux = parent;
			while (aux && !comp(val.first , aux->val.first))
				aux = aux->parent;
			return aux;
		}
		node *prev()
		{
			if (l)
				return getMax(l);
			node *aux = parent;
			while (aux && comp(val.first , aux->val.first))
				aux = aux->parent;
			return aux;
		}
	};


	/*
		NODE ITERATOR
	*/

	template <class Iter, class node>
	class TreeIterator : public ft::iterator<std::bidirectional_iterator_tag, Iter>
	{
	public:
		typedef Iter 															iterator_type;
		typedef Iter 															value_type;
		typedef typename std::bidirectional_iterator_tag 						iterator_category;
		typedef typename ft::iterator<iterator_category, Iter>::difference_type difference_type;
		typedef typename ft::iterator<iterator_category, Iter>::pointer 		pointer;
		typedef node 															*node_pointer;
		typedef typename ft::iterator<iterator_category, Iter>::reference 		reference;
		typedef typename ft::iterator<iterator_category, const Iter>::reference const_reference;
		node_pointer 	node_end;


		TreeIterator(void) : node_end(NULL),_base(NULL) {}
		TreeIterator(const node_pointer p,node_pointer _node_end) :node_end(_node_end), _base(p){}

		template <typename U>
		TreeIterator(const TreeIterator<U,node> &obj) :node_end(obj.node_end), _base(obj.base()){}
		~TreeIterator() {}
		reference operator*() const { return _base->val; }
		pointer operator->() const { return std::addressof(operator*()); }
		TreeIterator &operator++()
		{
			_base = _base->next();
			if(!_base)
				_base = node_end;
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
			if(_base == node_end)
				_base = node_end->parent;
			else
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
		bool operator==(TreeIterator const &i1) const {
			 return i1.base() == _base;
			 }

		bool operator!=(TreeIterator const &i1) const { return !(i1==*this); }
	private:
		node_pointer _base;
	};


	/*
		ALV TREE
	*/
	template <class Key, class val, class T = ft::pair<Key, val>, class Compare = std::less<Key>,class Alloc = std::allocator<Node<T,Compare> > >
	class Avl
	{

	public:
		typedef T 				value_type;
		typedef Key 			key_type;
		typedef Node<T,Compare> 		node;
		typedef node 			*node_pointer;
		typedef TreeIterator<T,node> iterator;
		typedef TreeIterator<T,node> const_iterator;


		Avl(Compare _comp = Compare(),Alloc alloc = Alloc()) : _root(NULL),_node_end(new node()), _size(0), comp(_comp), _allocator(alloc) {}
		~Avl() {}

		iterator begin() {
			if(_size == 0){
				return iterator(NULL,NULL);
			}
			return iterator(_root->getMin(NULL),_node_end);
		}

		iterator end(){
			if(_size == 0) {
				return iterator(NULL,NULL);
			}
			_node_end->parent = _root->getMax(NULL);
			return iterator(_node_end,_node_end);
		}

		const_iterator cbegin() const {
			if(_size == 0){
				return iterator(NULL,NULL);
			}
			return const_iterator(_root->getMin(NULL),_node_end); }

		const_iterator cend() const {
			if(_size == 0){
				return iterator(NULL,NULL);
			}
			_node_end->parent = _root->getMax(NULL);
			return const_iterator(_node_end,NULL);
		}

		iterator rbegin() { return iterator(_root->getMax(NULL)); }

		iterator rend() { return begin(); }

		const_iterator crbegin(){ return const_iterator(_root->getMax(NULL));}

		const_iterator crend(){ return cbegin(); }

		size_t getSize() const { return _size; }


		node_pointer get(Key const &k) const
		{
			node *res = _get(k, _root);
			return res;
		}

		iterator find(Key const k) const {
			return iterator(get(k),_node_end);
		}

		void remove(Key k)
		{
			_deleteNode(k, &_root);
		}

		ft::pair<iterator, bool> insert(value_type pair)
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

		//review this insert in n not root REDO THIS!!!
		iterator insert_at (iterator position, const value_type& value){
			node_pointer n = NULL;
			if(position.base())
		 		n = _get(position->first,_root);
			_size++;
			node_pointer aux = new node(value);
			if(n)
				return  _insert(aux, &_root).first;

			return _insert(aux, &_root).first;

		}

		void clear() {
			_size = 0;
			_clear(_root);
			delete _root;
			_root = NULL;
		}

		size_t max_size() const {
			return _allocator.max_size();
		}



	private:
		node_pointer _root;
		node_pointer _node_end;
		size_t _size;
		Compare comp;
		Alloc _allocator;
		// no funciona
		node_pointer _deleteNode(Key key, node **n)
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
			if(!n)
				return ;
			if(n && n->r)
				_clear(n->r);
			if(n && n->l)
				_clear(n->l);
			delete n->l;
			n->l = NULL;
			n->r = NULL;
			delete n->r;
		}
		node *_get(Key key, node *n) const
		{
			if (n && n->val.first == key)
				return n;
			else if (n && n->l && comp(key, n->val.first))
				return _get(key, n->l);
			else if (n && n->r)
				return _get(key, n->r);
			return NULL;
		}

		node_pointer _rotLL(node *n)
		{
			if (!n->l)
				return NULL;
			node *a = n;
			node *aux = a->l;
			aux->parent = n->parent;
			a->l = aux->r;
			a->setChildParent();
			aux->r = a;
			aux->setChildParent();
			return aux;
		}

		node_pointer _rotRR(node *n)
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

		node_pointer _rotRL(node *n)
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

		node_pointer _rotLR(node *n)
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

		ft::pair<iterator, bool> _insert(node *n, node **curr)
		{
			node * ret =  NULL;
			if (n == NULL)
				return ft::make_pair(iterator(NULL,_node_end),false);
			if(*curr && n->val.first == (*curr)->val.first ){
				_size--;
				return ft::make_pair(iterator(*curr,_node_end),false);
			}
			if (!_root)
			{
				_root = n;
				return ft::make_pair(iterator(_root,_node_end),true);
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
			return ft::make_pair(iterator(n,_node_end),true);
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
