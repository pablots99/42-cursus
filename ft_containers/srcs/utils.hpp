/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:48:05 by ptorres           #+#    #+#             */
/*   Updated: 2022/03/01 03:10:19 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "iterators/iterator.hpp"
#include <functional>

namespace ft {

    /*
    *enable_if:
    *Is used fo the deduction for invalid types
    *right in the declaration of a template
    *is usefull when choosing an overload on a template class
    *doc:https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
    */
    template <bool, typename T = void>
    struct enable_if
    {};
    template <typename T>
    struct enable_if<true, T> {
    typedef T type;
    };


    /*
    (TODOOOOOO!!!!!!!!)
    *is_integral:
    *Checks whether T is an integral type
    *integral types:
    *bool, char, char16_t, char32_t, wchar_t, short, int, long, long long
    */
    template <class T>
    struct is_integral {};


    /*(CHANGE THIS I DONT LIKE IT)
    *lexicographical_compare(algorithm):
    *compare to iterator ranges until one element is not equivalent to the other,
    *If both sequences compare equal until one of them ends,
    *the shorter sequence is lexicographically less than the longer one.
    */
   template<class Iterator1, class Iterator2>
   bool lexicographical_compare(Iterator1 start1, Iterator1 end1,Iterator2 start2, Iterator2 end2)
   {
        while (start1!=end1 && start2 != end2)
        {
             if (*start2 <* start1)
                return false;
             else if (*start1< *start2)
                return true;
            ++start1;
            ++start2;
        }
        return (start2!=end2) && (start1 == end1);
   }



	template<class InputIt, class OutputIt>
	OutputIt copy(InputIt first, InputIt last, OutputIt d_first)
	{
    	for (; first != last; (void)++first, (void)++d_first) {
        	*d_first = *first;
    	}
    	return d_first;
	}

	template<class Iter>
	const// required since C++17
	typename ft::iterator_traits<Iter>::difference_type
    aux_distance(Iter first, Iter last, std::input_iterator_tag)
	{
    	typename std::iterator_traits<Iter>::difference_type result = 0;
    	while (first != last) {
        	++first;
        	++result;
    	}
    	return result;
	}

	template<class Iter>
	const typename std::iterator_traits<Iter>::difference_type
    distance(Iter first, Iter last)
	{
    	return aux_distance(first, last,typename ft::iterator_traits<Iter>::iterator_category());
	}

	template<class Key,class T,typename Compare = std::less<Key> >
	class BinarySearchTree {
		protected:
			Key									_key;
			T									_val;
			Compare								_comp;
			BinarySearchTree<Key, T, Compare>	*_root;
			BinarySearchTree<Key, T, Compare>	*_l;
			BinarySearchTree<Key, T, Compare>	*_r;
			static int p_space;
		public:
			BinarySearchTree():_key(),_val(),_comp(Compare()),_root(NULL),_l(NULL),_r(NULL){};
			BinarySearchTree(Key k, T t,BinarySearchTree<Key, T, Compare> *r):
				_key(k),_val(t),_comp(Compare()),_root(r),_l(NULL),_r(NULL){};


			void push(Key k,T t)
			{
				if(!_root) {
					_root = this;
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
						_l = new BinarySearchTree(k, t,_root);
				}
				else {
					if(_r)
						_r->push(k,t);
					else
						_r = new BinarySearchTree(k, t,_root);
				}
			}

			T get(Key k)
			{
				/*if _key*/
				if(_key == k)
					return _val;
				if(_comp(k, _key))
					return _l->get(k);
				else
					return _r->get(k);
				return T();
			}
			// void remove(Key k) {

			// }
			void print()
			{
				std::cout << "key: " << _key << ", val: " << _val << std::endl;
				p_space+=4;
				int aux = p_space;
				if(_l) {
					std::cout <<  std::string(p_space, ' ') << "L(" << p_space / 4 << ") -> ";
					_l->print();
				}
				p_space = aux;
				if(_r) {
					std::cout << std::string(p_space, ' ') << "R(" << p_space / 4 << ") -> ";
					_r->print();
				}

			}
	};
	template<class Key,class T, typename Compare >
	int BinarySearchTree<Key,T, Compare>::p_space = 0;









    /*pair:
    * is a class template that provides a way to store two heterogeneous objects as a single unit
	*/
  template<class T1,class T2>
  struct pair {
    /*types*/
    typedef T1 first_type;
    typedef T2 second_type;
    /*objects*/
    T1 first;
    T1 second;
    /*member fuctions*/
    pair() : first(), second() {}
    pair(T1 const& t1, T2 const& t2) : first(t1), second(t2) {}
    template <class U1, class U2>
    pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}
    pair& operator=(pair const& p) {
        first = p.first;
        second = p.second;
        return *this;
    }
};
    /*pair non member functions*/
    template< class T1, class T2 >
    pair<T1,T2> make_pair( T1& t, T2& u ){return new pair<T1,T2>(t, u);};

        /*operators*/
    template< class T1, class T2 >
    bool operator==(const pair<T1,T2> &p1, const pair<T1,T2>  &p2){
        return ((p1.first == p2.first) && (p1.second == p2.second));
    }

    template< class T1, class T2 >
    bool operator!=(const pair<T1,T2> &p1, const pair<T1,T2>  &p2){
        return !(p1 == p2);
    }
    template< class T1, class T2 >
    bool operator<(const pair<T1,T2> &p1, const pair<T1,T2>  &p2){
        return (((p1.first < p2.first) || (p1.second < p2.second)) && (p1.first < p2.first) );
    }

    template< class T1, class T2 >
    bool operator>(const pair<T1,T2> &p1, const pair<T1,T2>  &p2){
        return p2 < p1;
    }

    template< class T1, class T2 >
    bool operator>=(const pair<T1,T2> &p1, const pair<T1,T2>  &p2){
        return !(p1 < p2);
    }

    template< class T1, class T2 >
    bool operator<=(const pair<T1,T2> &p1, const pair<T1,T2>  &p2){
        return !(p1 > p2);
    }


}




#endif
