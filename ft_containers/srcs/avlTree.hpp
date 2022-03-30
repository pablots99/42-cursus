/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:45 by pablo             #+#    #+#             */
/*   Updated: 2022/03/30 04:23:17 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include "containers/stack.hpp"
#include <iostream>
#include <math.h>
#include <vector>


namespace ft {


		template<class T, class K>
		struct Node {
			T	value;
			K	key;
			Node<T, K> *r;
			Node<T, K> *l;
			int 		height;

			Node(K _key,T val):key(_key),value(val),l(NULL),r(NULL),height(1){}
			void updateHeight() {
				if(!r && !l) {
					height = 1;
					return ;
				}
				if(r && l) {
					if(l->height < r->height)
						height = r->height + 1;
					else
						height = l->height + 1;
				}
				else if(l && !r)
					height = l->height + 1;
				else if (r && !l)
					height = r->height + 1;
			}
			int getBalance() {
				if(l && r)
					return (l->height - r->height);
				if(l)
					return l->height;
				if(r)
					return -r->height;
				return 0;
			}
		};

		template<class Key,class T,typename Compare = std::less<Key> >
		class Avl {

				typedef Node<T, Key>   node;
			public:
				Avl():_root(NULL){}
				~Avl(){}


				T get(Key k){
					node * res = _get(k,_root);
					if(!res)
						return T();
						// trhow new error
					return res->value;
				}

				void remove(Key k) {


				}





				void insert(Key key, T val){
					node *n = new node(key,val);
					std::cout << "n: " << key << std::endl;
					_insert(n,&_root);
					std::cout << "--------------" << std::endl;
				}

				void print() {
					node *n = _root;
					ft::vector<node * > stk;
					size_t i = 1;
					size_t j = 0;
					size_t size = 1;
					size_t n_count = 0;
					size_t levels = 0;
					while(1) {
						if(stk.size() == 0)
							stk.push_back(n);
						n_count = 0;
						for (; j < size; j++)
						{
							if(stk[j]) {
								stk.push_back(stk[j]->l);
								stk.push_back(stk[j]->r);
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
							number = std::to_string(stk[i]->key) + "," + std::to_string(stk[i]->height);

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
				node *getRoot() const{
					return _root;
				}


			private:
				node *_root;

				node *deleteNode(Key k,node *n) {
					//memory destruction not node
					if(!n->l && ! n->r){
						//if root root == NULL?
						return NULL;
					}



				}

				node * _get(Key key, node *n) {
					if(n->key == key)
						return n;
					else if(key < n->key && n->l )
						return _get(key,n->l);
					else if(n->r)
						return _get(key,n->r);
					return NULL;
				}
				node * _rotLL(node *n){
					std::cout << "ll rotation " << std::endl;
					if(!n->l)
						return NULL;
					std::cout << "n " << n->key << std::endl;
					node *a = n;
					node *aux = a->l;
					a->l = aux->r;
					aux->r = a;
					return aux;
				}

				node *  _rotRR(node *n){
					std::cout << "rr rotation " << std::endl;
					if(!n->r)
						return NULL;
					node *a = n;
					node *aux = a->r;
					a->r = aux->l;
					aux->l = a;
					return aux;
				}

				node * _rotRL(node *n){
					if(!n->l)
						return NULL;
					node *aux =  n->r;
					node *aux2 = n->r->l;

					n->r = aux2->l;
					aux->l = aux2->r;
					aux2->l = n;
					aux2->r = aux;
					return aux2;

				}

				node * _rotLR(node *n){
					if(!n->l)
						return NULL;
					node *aux =  n->l;
					node *aux2 = n->l->r;

					n->l = aux2->r;
					aux->r = aux2->l;
					aux2->r = n;
					aux2->l = aux;
					return aux2;
				}




				void _insert(node *n,node **curr) {
					if(n == NULL)
						return ;
					if(!_root) {
						_root = n;
						return ;
					}
					//use compare?
					if(n->key < (*curr)->key)
					{
						if(!(*curr)->l)
							(*curr)->l = n;
						else {
							_insert(n,&(*curr)->l);
						}
					}
					else {
						if(!(*curr)->r)
							(*curr)->r = n;
						else {
							_insert(n,&(*curr)->r);
						}
					}
					//set height with childs is idilic?
					(*curr)->updateHeight();
					int balance = (*curr)->getBalance();
					if(balance == 2 && (*curr)->l && (*curr)->l->getBalance() == 1)
						(*curr) = _rotLL((*curr));
					else if(balance == -2 && (*curr)->r && (*curr)->r->getBalance() == -1)
						(*curr) = _rotRR((*curr));
					else if(balance == -2 && (*curr)->r && (*curr)->r->getBalance() == -1)
						(*curr) = _rotRL((*curr));
					else if(balance == 2 && (*curr)->l && (*curr)->l->getBalance() == -1)
						(*curr) = _rotLR((*curr));
					if((*curr)->l)
						(*curr)->l->updateHeight();
					if((*curr)->r)
						(*curr)->r->updateHeight();
					(*curr)->updateHeight();
				}


		};
};
