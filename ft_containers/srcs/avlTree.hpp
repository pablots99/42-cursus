/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   avlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:39:45 by pablo             #+#    #+#             */
/*   Updated: 2022/03/17 23:40:15 by ptorres          ###   ########.fr       */
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
			size_t b;
			Node(K _key,T val):key(_key),value(val),l(NULL),r(NULL),b(0){}
		};

		template<class Key,class T,typename Compare = std::less<Key> >
		class Avl {
			private:
				typedef Node<T, Key>   node;
				node *_root;
			public:
				Avl():_root(NULL){}

				node *getRoot() const{ 
					return _root;
				}


				void _rotLL(node **n){
					if(!(*n)->l)
						return ;
					node *aux = (*n)->l;
					(*n)->l = aux->r;
					aux->r = (*n);
					*n = aux;
				}
				
				void _rotRR(node **n){
					if(!(*n)->r)
						return ;
					node *aux = (*n)->r;
					(*n)->r = aux->l;
					aux->l = (*n);
					*n = aux;
				}	

				void _rotRL(node **n){
					if(!(*n)->r)
						return ;
					_rotLL(&(*n)->r);
					_rotRR(&(*n));

				}	
				
				void _rotLR(node **n){
					if(!(*n)->l)
						return ;
					_rotRR(&(*n)->l);
					_rotLL(&(*n));

				}	
				

				void rotRL() { 
					_rotRL(&_root);
				}
				void rotLR() { 
					_rotLR(&_root);
				}


				void rotRR(){ 
					_rotRR(&_root);
				}
				void rotLL(){ 
					_rotLL(&_root);
				}


				void insert(node *n,node *curr) { 
					if(n == NULL)
						return ;
					if(!_root) { 
						_root = n;
						return ;
					}
					if(n->key < curr->key)
					{
						if(!curr->l)
							curr->l = n;
						else 
							insert(n,curr->l);
					}
					else { 
						if(!curr->r)
							curr->r = n;
						else 
							insert(n,curr->r);
					}
				}
				
				
				
				
				void insert(Key key, T val){
					node *n = new node(key,val);
					insert(n,_root);
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
							number = std::to_string(stk[i]->key);

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
};
