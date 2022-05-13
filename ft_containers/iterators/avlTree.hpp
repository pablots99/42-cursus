/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:45 by pablo             #+#    #+#             */
/*   Updated: 2022/05/13 16:01:34 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_HPP
#define FT_TREE_HPP
#include <functional>
#include "../containers/stack.hpp"
#include "../utils.hpp"
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
		int getBalance() const
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


		node * getMin(node  *n)
		{
			if (!n)
				return getMin(this);
			if (!n)
				return NULL;
			if (!n->l)
				return n;
			return getMin(n->l);
		}

		const node * getMin(const node  *n) const
		{
			if (!n)
				return getMin(this);
			if (!n)
				return NULL;
			if (!n->l)
				return n;
			return getMin(n->l);
		}

		node *getMax(node  *n)
		{
			if (!n)
				return getMax(this);
			if (!n)
				return NULL;
			if (!n->r)
				return n;
			return getMax(n->r);
		}

		const node *getMax(const node  *n) const
		{
			if (!n)
				return getMax(this);
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
			while (aux  && !comp(val.first , aux->val.first))
				aux = aux->parent;
			return aux;
		}
		const node *next() const
		{
			if (r)
				return getMin(r);
			node *aux = parent;
			while (aux  && !comp(val.first , aux->val.first))
				aux = aux->parent;
			return aux;
		}
		node *prev()
		{
			if (l){
				return getMax(l);
			}
			node *aux = parent;
			while (aux &&  comp(val.first , aux->val.first))
				aux = aux->parent;
			return aux;
		}
		const node *prev() const
		{
			if (l){
				return getMax(l);
			}
			node *aux = parent;
			while (aux &&  comp(val.first , aux->val.first))
				aux = aux->parent;
			return aux;
		}
		T getVal() {
			return val;
		}
		const T getVal() const {
			return val;
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
		typedef node 															node_pointer;
		typedef typename ft::iterator<iterator_category, Iter>::reference 		reference;
		typedef typename ft::iterator<iterator_category, const Iter>::reference const_reference;
		node 	node_end;


		TreeIterator(void) : node_end(NULL),_base(NULL) {}
		TreeIterator(const node_pointer p,const node_pointer _node_end) : node_end(_node_end), _base(p){}


		template <typename U,typename N>
		TreeIterator(const TreeIterator<U,N> &obj) : node_end(obj.node_end), _base(obj.base()){}
		~TreeIterator() {}

		template <typename U,typename N>
		TreeIterator  &operator=(TreeIterator<U,N> const &obj ){
			node_end = obj.node_end;
			_base = obj.base();
			return *this;
		}


		reference operator*()  const { return _base->val; }
		pointer operator->()  const { return &_base->val; }



		operator TreeIterator<const Iter, node>(void) const {
			return TreeIterator<const Iter, node>(this->_base);
		}

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
			if(_base == node_end) {
				_base = _base->parent;

				return *this;
			}
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

	template <typename U, typename N,typename U1, typename N1>
	bool operator==(TreeIterator<U,N> const &i1,TreeIterator<U1,N1> const &i2) {
			 return i1.base() == i2.base();
	}


	template <typename U, typename N,typename U1, typename N1>
	bool operator!=(TreeIterator<U,N> const &i1,TreeIterator<U1,N1> const &i2) {
			 return !(i1==i2);
	}



	/*
		ALV TREE
	*/


	template <class Key, class val, class T = ft::pair<Key, val>, class Compare = std::less<Key>,class Alloc= std::allocator<ft::pair<Key, val> > >
	class Avl
	{

	public:
		typedef T 											 value_type;
		typedef Key 										 key_type;
		typedef Node<T,Compare> 							 node;
		typedef typename Alloc::template rebind<node>::other node_allocator;
		typedef typename std::allocator<Node<T,Compare> > 	_allocator;
		typedef typename node_allocator::const_pointer		const_node_Pointer;
		typedef node 										*node_pointer;
		typedef TreeIterator<T,node_pointer> 				iterator;
		typedef TreeIterator<const T,const_node_Pointer>  	const_iterator;



		Avl(Compare _comp = Compare(),node_allocator alloc = node_allocator()) : _root(NULL), _size(0),
		comp(_comp), _n_allocator(alloc) {
			_node_end = new_node();
		}
		~Avl() {
			_clear(_root);
			_clear(_node_end);
		}



		/*

			iterators

		*/
		iterator begin() {
			if(_size == 0){
				return end();
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

		const_iterator cbegin() const{
			if(_size == 0){
				return cend();
			}
			return const_iterator(_root->getMin(NULL),_node_end); }

		const_iterator cend() const {
			if(_size == 0){
				return const_iterator(NULL,NULL);
			}
			_node_end->parent = _root->getMax(NULL);
			return const_iterator(_node_end,_node_end);
		}

		iterator rbegin() {
			if(_size == 0){
				return iterator(NULL,NULL);
			}
			return end();
		}

		iterator rend() {
			if(_size == 0) {
				return iterator(NULL,NULL);
			}
			return iterator(_root->getMin(NULL),_node_end);
		}

		const_iterator crbegin(){
			if(_size == 0){
				return const_iterator(NULL,NULL);
			}
			return cend();
		}

		const_iterator crend(){
			if(_size == 0) {
				return const_iterator(NULL,NULL);
			}
			return const_iterator(_root->getMin(NULL),_node_end);
		}

		size_t getSize() const { return _size; }


		node_pointer get(Key const &k) const
		{
			node *res = _get(k, _root);
			return res;
		}

		iterator find(Key const k)  {
			return iterator(get(k),_node_end);
		}

		const_iterator find(Key const k) const {
			return const_iterator(get(k),_node_end);
		}

		size_t remove(Key k)
		{
			size_t ret = _size;
			return ret != _deleteNode(k, &_root);
		}

		void remove(iterator it) {
			_deleteNode(it->first, &_root);
		}

		ft::pair<iterator, bool> insert(value_type pair)
		{
			node *n = new_node(pair);
			ft::pair<iterator, bool> r = _insert(n, &_root);
			return r;
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
			node_pointer aux = new_node(value);
			if(n)
				return  _insert(aux, &_root).first;

			return _insert(aux, &_root).first;

		}

		void clear() {
			_size = 0;
			_clear(_root);
			_root = NULL;
		}

		size_t max_size() const {
			return _n_allocator.max_size();
		}

		iterator get_upper_iter(const key_type &key)
		{
			node *ret = _root->getMin(NULL);

			while(ret && !comp(key,ret->val.first))
				ret = ret->next();
			if(!ret)
				return end();
			return iterator(ret,_node_end);
		}

		const_iterator get_upper_iter(const key_type &key) const
		{
			node *ret = _root->getMin(NULL);

			while(ret && !comp(key,ret->val.first))
				ret = ret->next();
			if(!ret)
				return cend();
			return const_iterator(ret,_node_end);
		}



		iterator get_lower_node(const key_type &key)
		{
			node *ret = _root->getMin(NULL);

			while(ret && comp(ret->val.first,key))
				ret = ret->next();
			if(!ret)
				return end();
			return iterator(ret,_node_end);
		}

		iterator get_lower_iter(const key_type &key)
		{
			node *ret = _root->getMin(NULL);

			while(ret && comp(ret->val.first,key))
				ret = ret->next();
			if(!ret)
				return end();
			return iterator(ret,_node_end);
		}

		const_iterator get_lower_iter(const key_type &key) const
		{
			node *ret = _root->getMin(NULL);

			while(ret && comp(ret->val.first,key))
				ret = ret->next();
			if(!ret)
				return cend();
			return const_iterator(ret,_node_end);
		}



	private:
		node_pointer _root;
		node_pointer _node_end;
		size_t _size;
		Compare comp;
		node_allocator _n_allocator;

		// val(),  r(NULL), l(NULL), parent(NULL), height(0),comp(_comp) {}
		node *new_node() {
			node * ret = _n_allocator.allocate(1);
			_n_allocator.construct(ret ,node());
			return ret;
		}
		node *new_node(value_type v) {
			node * ret = _n_allocator.allocate(1);
			_n_allocator.construct(ret ,node(v));
			return ret;
		}

		void _deallocate(node **n) {
			if(*n) {
				_n_allocator.destroy(*n);
				_n_allocator.deallocate(*n,1);
			}
			*n = NULL;
		}

		size_t _deleteNode(Key key, node **n)
		{
			size_t ret = 0;
			if ((*n) && (*n)->val.first == key) {

				node *aux = NULL;
				if((*n)->r)
					aux = (*n)->r->getMin(NULL);
				else if((*n)->l)
					aux = (*n)->l->getMax(NULL);
				else {
					aux = *n;
				}

				if(aux == (*n)){
					_deallocate(n);
					(*n) = NULL;
				}
				else {
					if(aux == aux->parent->r)
						aux->parent->r = aux->r;
					if(aux == aux->parent->l)
						aux->parent->l = aux->l;
					if(aux != (*n)->l)
						aux->l = (*n)->l;
					if(aux != (*n)->r)
						aux->r = (*n)->r;
					aux->parent = (*n)->parent;
					aux->setChildParent();
					if(aux == _root)
					{
						_deallocate(&_root);
						_root = aux;
					}
					_deallocate(n);
					(*n) = aux;
				}
				_size--;
				ret =  1;
			}
			else if ((*n) && (*n)->l && comp(key, (*n)->val.first))
				  _deleteNode(key, &(*n)->l);
			else if ((*n)  && (*n) ->r)
				  _deleteNode(key, &(*n)->r);

			if(*n)
			{
				(*n)->updateHeight();
				int balance = (*n)->getBalance();
				if (balance == 2 && (*n)->l && (*n)->l->getBalance() == 1)
					(*n) = _rotLL((*n));
				else if (balance == -2 && (*n)->r && (*n)->r->getBalance() == -1)
					(*n) = _rotRR((*n));
				else if (balance == -2 && (*n)->r && (*n)->r->getBalance() == 1)
					(*n) = _rotRL((*n));
				else if (balance == 2 && (*n)->l && (*n)->l->getBalance() == -1)
					(*n) = _rotLR((*n));
				if(*n){
					if ((*n)->l)
						(*n)->l->updateHeight();
					if ((*n)->r)
						(*n)->r->updateHeight();
					(*n)->updateHeight();
				}
			}
			return ret;
		}

		void _clear(node *n) {
			if(!n)
				return ;
			if(n && n->r)
				_clear(n->r);
			if(n && n->l)
				_clear(n->l);
			_deallocate(&n);
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
			// std::cout << "rotll" << std::endl;
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
			// std::cout << "rotrr" << std::endl;
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
			if (!n->r)
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
			// std::cout << "rotlr" << std::endl;
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
			if (n == NULL)
				return ft::make_pair(iterator(NULL,_node_end),false);
			if(*curr && n->val.first == (*curr)->val.first ){
				return ft::make_pair(iterator(*curr,_node_end),false);
			}
			if (!_root)
			{
				_root = n;
				_size = 1;
				return ft::make_pair(iterator(_root,_node_end),true);
			}
			if (comp(n->val.first, (*curr)->val.first))
			{
				if (!(*curr)->l)
				{
					n->parent = *curr;
					(*curr)->l = n;
					_size++;
				}
				else
					_insert(n, &(*curr)->l);
			}
			else
			{
				if (!(*curr)->r)
				{
					n->parent = *curr;
					(*curr)->r = n;
					_size++;
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
			else if (balance == -2 && (*curr)->r && (*curr)->r->getBalance() == 1)
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
		// void print()
		// {
		// 	node *n = _root;
		// 	ft::vector<node *> stk;
		// 	size_t i = 1;
		// 	size_t j = 0;
		// 	size_t size = 1;
		// 	size_t n_count = 0;
		// 	size_t levels = 0;
		// 	while (1)
		// 	{
		// 		if (stk.size() == 0)
		// 			stk.push_back(n);
		// 		n_count = 0;
		// 		for (; j < size; j++)
		// 		{
		// 			if (stk[j])
		// 			{
		// 				stk.push_back(stk[j]->l);
		// 				stk.push_back(stk[j]->r);
		// 			}
		// 			else
		// 			{
		// 				stk.push_back(NULL);
		// 				stk.push_back(NULL);
		// 				n_count++;
		// 			}
		// 		}
		// 		if (n_count == i)
		// 		{
		// 			for (i = 0; i < n_count + (n_count * 2); i++)
		// 				stk.pop_back();
		// 			break;
		// 		}
		// 		levels++;
		// 		i *= 2;
		// 		size += i;
		// 	}
		// 	n_count /= 2;
		// 	size = ((3 + 5) * n_count) / 2;
		// 	int sp = 11 << (levels - 2); // 11 = 3 * 2 + 5
		// 	size_t level = 1;
		// 	j = 1;
		// 	for (i = 0; i < stk.size(); i++)
		// 	{

		// 		if (i == 0)
		// 			std::cout << std::string(size, ' ');
		// 		if (i == j || i == 1)
		// 		{
		// 			size /= 2;
		// 			std::cout << "\n\n"
		// 					  << std::string(size, ' ');
		// 			sp /= 2;
		// 			level++;
		// 			j = (j * 2) + 1;
		// 		}
		// 		std::string number = "N    ";
		// 		if (stk[i])
		// 		{
		// 			if (stk[i]->parent != NULL)
		// 				number = std::to_string(stk[i]->val.first ) + "," + std::to_string(stk[i]->getBalance());
		// 			else
		// 				number = std::to_string(stk[i]->val.first) + ", ()";
		// 		}
		// 		std::cout << number;
		// 		if (number.length() < 5)
		// 			std::cout << std::string(5 - number.length(), ' ');

		// 		if (level == levels - 1)
		// 			sp = 6;
		// 		if (level == levels)
		// 			sp = -2;
		// 		std::cout << std::string(sp + 5, ' ');
		// 	}
		// 	std::cout << "\n\n---------------------------------------------\n";
		// }
	};

};


//    template <class Iter, class node>
// 	class ConstTreeIterator : public ft::iterator<std::bidirectional_iterator_tag, Iter>
// 	{
// 	public:
// 		typedef Iter 															iterator_type;
// 		typedef Iter 															value_type;
// 		typedef typename std::bidirectional_iterator_tag 						iterator_category;
// 		typedef typename ft::iterator<iterator_category, Iter>::difference_type difference_type;
// 		typedef typename ft::iterator<iterator_category, Iter>::pointer 		pointer;
// 		typedef node 															*node_pointer;
// 		typedef typename ft::iterator<iterator_category, Iter>::reference 		reference;
// 		typedef typename ft::iterator<iterator_category, const Iter>::reference const_reference;
// 		node_pointer 	node_end;


// 		ConstTreeIterator(void) : node_end(NULL),_base(NULL) {}
// 		ConstTreeIterator(const node_pointer p,const node_pointer _node_end) :node_end(_node_end), _base(p){}
// 		template <typename U,typename N>
// 		ConstTreeIterator(const ConstTreeIterator<U,N> &obj) :node_end(obj.node_end), _base(obj.base()){}

// 		template <typename U,typename N>
// 		ConstTreeIterator(const TreeIterator<U,N> &obj) :node_end(obj.node_end), _base(obj.base()){}
// 		~ConstTreeIterator() {}

// 		template <typename U,typename N>
// 		ConstTreeIterator  &operator=(ConstTreeIterator<U,N> const &obj ){
// 			node_end = obj.node_end;
// 			_base = obj.base();
// 			return *this;
// 		}


// 		template <typename U,typename N>
// 		ConstTreeIterator  &operator=(TreeIterator<U,N> const &obj ){
// 			node_end = obj.node_end;
// 			_base = obj.base();
// 			return *this;
// 		}

// 		const_reference operator*() const { return _base->val; }

// 		pointer operator->() const  { return &_base->val;}

// 		ConstTreeIterator &operator++()
// 		{
// 			_base = _base->next();
// 			if(!_base)
// 				_base = node_end;
// 			return *this;
// 		}
// 		ConstTreeIterator operator++(int)
// 		{
// 			ConstTreeIterator tmp(*this);
// 			++*this;
// 			return tmp;
// 		}
// 		ConstTreeIterator &operator--()
// 		{
// 			if(_base == node_end) {
// 				_base = _base->parent;

// 				return *this;
// 			}
// 			_base = _base->prev();
// 			return *this;
// 		}
// 		ConstTreeIterator operator--(int)
// 		{
// 			ConstTreeIterator tmp(*this);
// 			--*this;
// 			return tmp;
// 		}
// 		ConstTreeIterator base() const {
// 			return _base;
// 		}
// 	private:
// 		node_pointer _base;
// 	};
// 	template <typename U,typename N>
// 	bool operator==(ConstTreeIterator<U,N> const &i1,ConstTreeIterator<U,N> const &i2)  {
// 			 return i1.base() == i2.base();
// 	}
// 	template <typename U,typename N>
// 	bool operator!=(ConstTreeIterator<U,N> const &i1,ConstTreeIterator<U,N> const &i2)  {
// 			 return !(i1==i2);
// 	}



#endif
