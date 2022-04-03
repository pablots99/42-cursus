/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaryTree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:19:22 by pablo             #+#    #+#             */
/*   Updated: 2022/04/03 23:37:26 by ptorres          ###   ########.fr       */
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
			bool								_root;

			BinarySearchTree* _getReplace() {
				BinarySearchTree *aux = this;
				while (aux->getR() || aux->getL())
					if(aux->getR())
						aux = aux->getR();
					else
						aux = aux->getL();
				return aux;
			}


		public:
			BinarySearchTree():_key(),_val(),_comp(Compare()),_parent(NULL),_l(NULL),_r(NULL),_root(false){};
			BinarySearchTree(Key k, T t,BinarySearchTree<Key, T, Compare> *r):
			key(k),_val(t),_comp(Compare()),_parent(r),_l(NULL),_r(NULL),_root(false){};

			BinarySearchTree &operator=(BinarySearchTree  &obj){

				std::cout << "ewaewaewa" <<std::endl;
				_key = obj.getKey();
				_val = obj.getVal();
				_l =   obj.getL();
				_r = obj.getR();
				_comp = Compare();
				if(isRoot()){
					_parent = &obj;
				}
				if(!_parent)
					_parent = obj.getParent();
				return *this;
			}
			void insert(Key k,T t)
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
						_l->insert(k,t);
					else
						_l = new BinarySearchTree(k, t,this);
				}
				else {
					if(_r)
						_r->insert(k,t);
					else
						_r = new BinarySearchTree(k, t,this);
				}
			}

			BinarySearchTree* search(Key k)
			{
				if(_key == k)
					return this;
				if(_comp(k, _key))
					return _l->search(k);
				else
					return _r->search(k);
				return NULL;
			}

			BinarySearchTree* getMax() {
				BinarySearchTree *aux = this;
				while (aux->getR())
					aux = aux->getR();
				return aux;
			}

			BinarySearchTree* getMin()  {
				BinarySearchTree *aux = this;
				while (aux->getL())
					aux = aux->getL();
				return aux;
			}


			bool isRoot()const {
				return _key == _parent->getKey();
			}
			void setR(BinarySearchTree *r) {
					_r = r;
			}

			void setL(BinarySearchTree *l) {
					_l = l;
			}

			void setParent(BinarySearchTree *p) {
					_parent = p;
			}

			BinarySearchTree *getParent() const {
				return _parent;
			}

			void removeKey(Key key) {
				search(key)->removeSelf();
			}

			void removeSelf() {
				BinarySearchTree *rep = _getReplace();
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




			BinarySearchTree* getR() const{
				return _r;
			}

			BinarySearchTree* getL() const{
				return _l;
			}

			Key getKey() const {
				return _key;
			}

			T getVal() const{
				return _val;
			}



			void rotRigth(BinarySearchTree  *node) {
				BinarySearchTree *aux = node->getL();
				node->setL(aux->getR());
				node->getL()->setParent(node);
				node->setParent(aux);
				aux->setR(node);
				*node = *aux;
			}

			bool rotR() {
				rotRigth(this);
				return false;
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

}
