/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:48:05 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/08 19:06:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  UTILS_HPP
#define UTILS_HPP

#include <iostream>



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
        while (start1!=end1)
        {
             if (start2==end2 || *start2<*start1)
                return false;
             else if (*start1<*start2)
                return true;
            ++start1;
            ++start2;
        }
        return (start2!=end2);
   }

    /*pair:
    * is a class template that provides a way to store two heterogeneous objects as a single unit
    */
  std::pair<int,int>;
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
    pair<T1,T2> make_pair( T1&& t, T2&& u ){return new pair<T1,T2>(t, u)};
    
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
        return ((p1.first < p2.first) || (p1.second < p2.second) && (p1.first < p2.first) );
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
