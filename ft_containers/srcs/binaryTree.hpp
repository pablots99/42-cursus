/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:19:22 by pablo             #+#    #+#             */
/*   Updated: 2022/03/03 00:46:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include "containers/stack.hpp"
#include <iostream>
#include <math.h>
namespace ft {


	template<class Key,class T,typename Compare = std::less<Key> >
	class BinarySearchTree {
		protected:
			Key									_key;
			T									_val;
			Compare								_comp;
			BinarySearchTree<Key, T, Compare>	*_parent;
			BinarySearchTree<Key, T, Compare>	*_l;
			BinarySearchTree<Key, T, Compare>	*_r;
			static int p_space;
		public:
			BinarySearchTree():_key(),_val(),_comp(Compare()),_parent(NULL),_l(NULL),_r(NULL){};
			BinarySearchTree(Key k, T t,BinarySearchTree<Key, T, Compare> *r):
				_key(k),_val(t),_comp(Compare()),_parent(r),_l(NULL),_r(NULL){};


			void push(Key k,T t)
			{
				if(!_parent) {
					_parent = this;
					_val = t;
					_key = k;
					return ;
				}
				/*exception*/
				if(k ==  _key)
					return ;
				if(_comp(k, _key)) {
					if(_l)
						_l->push(k,t);
					else
						_l = new BinarySearchTree(k, t,this);
				}
				else {
					if(_r)
						_r->push(k,t);
					else
						_r = new BinarySearchTree(k, t,this);
				}
			}

			BinarySearchTree* get(Key k)
			{
				/*if _key*/
				if(_key == k)
					return this;
				if(_comp(k, _key))
					return _l->get(k);
				else
					return _r->get(k);
				return NULL;
			}

			BinarySearchTree* getMax() {
				BinarySearchTree *aux = this;
				while (aux->getR())
					aux = aux->getR();
				return aux;
			}

			void setR(BinarySearchTree *r) {
					_r = r;
			}

			void setL(BinarySearchTree *l) {
					_l = l;
			}
			BinarySearchTree & operator=(BinarySearchTree const &obj) {
				*this = obj;
				return *this;
			}

			BinarySearchTree *getParent() {
				return _parent;
			}

			void removeKey(Key k) {
				BinarySearchTree *aux = get(k)->getParent();
				BinarySearchTree *max = aux->getMax();
				// if(max->getR()->getKey() == aux->getKey())
				// 	max->setR(NULL);
				// else
				// 	max->setR(aux->getR());
				// max->setL(aux->getL());

			}

			void removeSelf() {
				BinarySearchTree *max = getMax();

			}


			BinarySearchTree* getR() {
				return _r;
			}

			BinarySearchTree* getL() {
				return _l;
			}




			Key getKey() {
				return _key;
			}






			void print()
			{

				ft::vector<	BinarySearchTree<Key, T, Compare>	* > stk;
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
	template<class Key,class T, typename Compare >
	int BinarySearchTree<Key,T, Compare>::p_space = 0;




}
