/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:06:32 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/10 16:48:48 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include "./iterator_traits.hpp"

namespace ft {

    template<class Iter>
    class reverse_iterator 
    {       
        private:
            Iter __t;
        protected: 
            Iter current;
        public:   
            /* iterator traits*/
            typedef  Iter                                                   iterator_type;
            typedef typename ft::iterator_traits<Iter>::difference_type     difference_type;
            typedef typename ft::iterator_traits<Iter>::pointer             pointer;
            typedef typename ft::iterator_traits<Iter>::reference           reference;
            /******************/
            
            
            /*constructors*/
            reverse_iterator():__t(),  current() {}
            explicit reverse_iterator(Iter x ):__t(x), current(x) {}
            template< class U >
            reverse_iterator( const reverse_iterator<U>& obj ):__t(obj.base()), current(obj.base()){}
            /**************/

            Iter base() const {return current;}
            
            /*operators*/
            template< class U >
            reverse_iterator& operator=( const reverse_iterator<U>& other ){current = other.base(); return *this;}
            
            /*it is --because otherqise the value would be NULL*/
            reference operator*() const {Iter tmp = current; return *--tmp;}

            pointer  operator->() const {return std::addressof(operator*());}


            reverse_iterator& operator++() {--current; return *this;}
            reverse_iterator  operator++(int) {reverse_iterator tmp(*this); --current; return tmp;}
            
            reverse_iterator& operator--() {++current; return *this;}
            reverse_iterator  operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;}
            

            //difference_type instead iter? 
            reverse_iterator& operator+=(Iter i) {current-= i; return *this;}
            reverse_iterator& operator-=(Iter i) {current+= i; return *this;}
            reverse_iterator& operator-(Iter i) {return reverse_iterator(current + i);}
            reverse_iterator& operator+(Iter i) {return reverse_iterator(current - i);}

            /**************************+*/ 
    };
    template<class Iter1, class Iter2>
    bool operator==(const reverse_iterator<Iter1> &i1,reverse_iterator<Iter2> &i2) { return i1.base() == i2.base();}
    
    
    template<class Iter1, class Iter2>
    bool operator!=(const reverse_iterator<Iter1> &i1,reverse_iterator<Iter2> &i2) { return i1.base() != i2.base();}

    template<class Iter1, class Iter2>
    bool operator<(const reverse_iterator<Iter1> &i1,reverse_iterator<Iter2> &i2) { return i1.base() < i2.base();}
   
    template<class Iter1, class Iter2>
    bool operator<=(const reverse_iterator<Iter1> &i1,reverse_iterator<Iter2> &i2) { return i1.base() <= i2.base();}
   
    template<class Iter1, class Iter2>
    bool operator>(const reverse_iterator<Iter1> &i1,reverse_iterator<Iter2> &i2) { return i1.base() > i2.base();;}
   
    template<class Iter1, class Iter2>
    bool operator>=(const reverse_iterator<Iter1> &i1,reverse_iterator<Iter2> &i2) { return i1.base() >= i2.base();}
    
    template<class Iter1, class Iter2>
    typename reverse_iterator<Iter1>::difference_type
    operator-(const reverse_iterator<Iter1>& i1, const reverse_iterator<Iter2>& i2){return i1.base() - i2.base();}
    
    template<class Iter1, class Iter2>
    typename reverse_iterator<Iter1>::difference_type
    operator+(const reverse_iterator<Iter1>& i1, const reverse_iterator<Iter2>& i2){return i1.base() + i2.base();}

};
#endif