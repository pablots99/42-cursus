/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:19:22 by pablo             #+#    #+#             */
/*   Updated: 2022/03/03 18:46:19 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include "containers/stack.hpp"
#include <iostream>
#include <math.h>

#define RED true;
#define BLACK false;


namespace ft {


	template<class Key,class T,typename Compare = std::less<Key> >
	class RedBlackTree {
		protected:
			Key									_key;
			T									_val;
			Compare								_comp;
			RedBlackTree<Key, T, Compare>	*_parent;
			RedBlackTree<Key, T, Compare>	*_l;
			RedBlackTree<Key, T, Compare>	*_r;
			bool								_root;
            bool                                _color;
			
			RedBlackTree* _getReplace() {
				RedBlackTree *aux = this;
				while (aux->getR() || aux->getL())
					if(aux->getR())
						aux = aux->getR();
					else
						aux = aux->getL();
				return aux;
			}
            void _insert(Key k,T t)
			{
				if(!_parent) {
					_parent = this;
					_root = true;
					_val = t;
					_key = k;
					return ;
				}
				if(k ==  _key)
					return ;
				if(_comp(k, _key)) {
					if(_l)
						_l->_insert(k,t);
					else
						_l = new RedBlackTree(k, t,this);
				}
				else {
					if(_r)
						_r->_insert(k,t);
					else
						_r = new RedBlackTree(k, t,this);
				}
                
			}
		public:
			RedBlackTree():_key(),_val(),_comp(Compare()),_parent(NULL),_l(NULL),_r(NULL),_root(false){};
			RedBlackTree(Key k, T t,RedBlackTree<Key, T, Compare> *r):
				_key(k),_val(t),_comp(Compare()),_parent(r),_l(NULL),_r(NULL),_root(false){};


          
			RedBlackTree* getMax() {
				RedBlackTree *aux = this;
				while (aux->getR())
					aux = aux->getR();
				return aux;
			}

			RedBlackTree* getMin() {
				RedBlackTree *aux = this;
				while (aux->getL())
					aux = aux->getL();
				return aux;
			}

			RedBlackTree* search(Key k)
			{	
				if(_key == k)
					return this;
				if(_comp(k, _key))
					return _l->search(k);
				else
					return _r->search(k);
				return NULL;
			}


			RedBlackTree & operator=(RedBlackTree const &obj) {
				std::cout << "operator" << std::endl;
				*this = obj;
				return *this;
			}

			RedBlackTree *getParent() {
				return _parent;
			}

			void removeKey(Key key) { 
				search(key)->removeSelf();
			}
			
			void removeSelf() {
				RedBlackTree *rep = _getReplace();
				if(_l || _r){
					if(_l && rep->getKey() == _l->getKey())
						rep->setL(NULL);
					else
						rep->setL(_l);
					
					if(_r && rep->getKey() == _r->getKey())
						rep->setR(NULL);
					else
						rep->setR(_r);
					
					if(rep->getParent()->getL()->getKey() == rep->getKey())
							rep->getParent()->setL(NULL);
					else
							rep->getParent()->setR(NULL);

					rep->setParent(_parent);
				}
				else 
					rep = NULL;
				if(_root)
				{
					_key  = rep->getKey();
					_val = rep->getVal();
					delete rep;
					return ;
				}
				if(_parent->getR() && _parent->getR()->getKey() == _key) {
						delete _parent->getR();
						_parent->setR(rep);
				}
				else { 
						delete _parent->getL();
					 	_parent->setL(rep);
				}
			}

             void setR(RedBlackTree *r) {
					_r = r;
			}

			void setL(RedBlackTree *l) {
					_l = l;
			}

			void setParent(RedBlackTree *p) {
					_parent = p;
			}

			RedBlackTree* getR() {
				return _r;
			}

			RedBlackTree* getL() {
				return _l;
			}

			Key getKey() {
				return _key;
			}

			T getVal() {
				return _val;
			}

            
			void print()
			{

				ft::vector<	RedBlackTree<Key, T, Compare>	* > stk;
				size_t i = 1;
				size_t j = 0;
				size_t size = 1;
				size_t n_count = 0;
				size_t levels = 0;
				while(1) {
					if(stk.size() == 0)
						stk.push_back(this);
					n_count = 0;
					for (; j < size; j++)
					{
						if(stk[j]) {
							stk.push_back(stk[j]->getL());
							stk.push_back(stk[j]->getR());
						}
						else {
							stk.push_back(NULL);
							stk.push_back(NULL);
							n_count++;
						}
					}
					if(n_count == i)
					{
						for(i = 0; i< n_count +( n_count*2); i++)
							stk.pop_back();
						break ;
					}
					levels++;
					i *= 2;
					size += i;
				}
				n_count/=2;
				size = ((3+5) * n_count)/ 2;
				int sp = 11 << (levels - 2);//11 = 3 * 2 + 5
				size_t level  = 1;
				std::cout << n_count << "," << levels << "," << sp << ","  << size  <<  std::endl;
				j = 1;
				for ( i = 0; i < stk.size(); i++)
				{

					if(i == 0)
						std::cout << std::string(size,' ');
					if(i == j || i == 1){
						size /= 2;
						std::cout << "\n\n" << std::string(size,' ');
						sp /= 2;
						level++;
						j = (j*2) + 1;
					}
					std::string number = "N    ";
					if(stk[i])
						number = std::to_string(stk[i]->getKey());

					std::cout << number;
					if(number.length() < 5)
						std::cout << std::string(5-number.length(),' ');


					if(level == levels -1)
						sp = 6;
					if(level == levels)
						sp = -2;
					//spaces between numbers
					std::cout  << std::string(sp + 5,' ');
				}
				std::cout   << "\n\n";

			}
	};

}
