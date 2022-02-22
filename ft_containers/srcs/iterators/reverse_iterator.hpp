/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:06:32 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/22 20:12:44 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include <iostream>
#include "./iterator_traits.hpp"

namespace ft
{

template <class Iter>
class reverse_iterator : public iterator<typename ft::iterator_traits<Iter>::iterator_category,
                                         typename ft::iterator_traits<Iter>::value_type,
                                         typename ft::iterator_traits<Iter>::difference_type,
                                         typename ft::iterator_traits<Iter>::pointer,
                                         typename ft::iterator_traits<Iter>::reference>
{
private:
    Iter __t;


public:
    /* iterator traits*/
    typedef Iter iterator_type;
    typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
    typedef typename ft::iterator_traits<Iter>::pointer pointer;
    typedef typename ft::iterator_traits<Iter>::reference reference;
    typedef typename ft::iterator_traits<Iter>::reference const const_reference;
    /******************/

    /*constructors*/
    reverse_iterator() : __t(), current() {}
    explicit reverse_iterator(Iter x) : __t(x), current((pointer)x.base()) {}
    template <class U>
    reverse_iterator(const reverse_iterator<U> &obj) : __t(obj.base()), current(obj.base()) {}
    /**************/

    Iter base() const { return current; }

    /*operators*/
    template <class U>
    reverse_iterator &operator=(const reverse_iterator<U> &other)
    {
        current = other.base();
        return *this;
    }
    reference operator*() const
    {
        pointer tmp = current;
        return *--tmp;
    }
    pointer operator->() const { return std::addressof(operator*()); }
    reference operator[](int n) { return (*(current + n)); }
    const_reference operator[](int n) const { return (*(current + n)); }
    reverse_iterator &operator++()
    {
        --current;
        return *this;
    }
    reverse_iterator operator++(int)
    {
        reverse_iterator tmp(*this);
        --current;
        return tmp;
    }
    reverse_iterator &operator--()
    {
        ++current;
        return *this;
    }
    reverse_iterator operator--(int)
    {
        reverse_iterator tmp(*this);
        ++current;
        return tmp;
    }
    const reverse_iterator operator+=(const difference_type i)
    {
        current -= i;
        return *this;
    }
    const reverse_iterator operator-=(const difference_type i)
    {
        current -= i;
        return *this;
    }

    reverse_iterator operator-(const difference_type n) const { return reverse_iterator(current + n); }
    reverse_iterator operator+(const difference_type n) const { return reverse_iterator(current - n); }
    /**************************+*/
    protected:
         pointer current;
        reverse_iterator(pointer x) : __t(x), current(x) {}



};
template <class Iter1, class Iter2>
bool operator==(const ft::reverse_iterator<Iter1> &i1, const ft::reverse_iterator<Iter2> &i2) { return i1.base() == i2.base(); }

template <class Iter1, class Iter2>
bool operator!=(const ft::reverse_iterator<Iter1> &i1, const ft::reverse_iterator<Iter2> &i2) { return i1.base() != i2.base(); }

template <class Iter1, class Iter2>
bool operator<(const ft::reverse_iterator<Iter1> &i1, const ft::reverse_iterator<Iter2> &i2) { return i1.base() > i2.base(); }

template <class Iter1, class Iter2>
bool operator<=(const ft::reverse_iterator<Iter1> &i1, const ft::reverse_iterator<Iter2> &i2) { return i1.base() >= i2.base(); }

template <class Iter1, class Iter2>
bool operator>(const ft::reverse_iterator<Iter1> &i1, const ft::reverse_iterator<Iter2> &i2)
{
    return i1.base() < i2.base();
}

template <class Iter1, class Iter2>
bool operator>=(const ft::reverse_iterator<Iter1> &i1, const ft::reverse_iterator<Iter2> &i2) { return i1.base() <= i2.base(); }

template <class Iter>
const ft::reverse_iterator<Iter>
operator+(typename ft::reverse_iterator<Iter>::difference_type n,
          const ft::reverse_iterator<Iter> &it)
{
    return reverse_iterator<Iter>(it.base() - n);
}

template <class Iter>
const ft::reverse_iterator<Iter>
operator-(typename ft::reverse_iterator<Iter>::difference_type n,
          const ft::reverse_iterator<Iter> &it)
{
    return reverse_iterator<Iter>(it.base() + n);
}
}; // namespace ft
#endif
