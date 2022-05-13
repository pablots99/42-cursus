/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_acces_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:17:31 by ptorres           #+#    #+#             */
/*   Updated: 2022/05/13 15:43:08 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef random_iterator_hpp
#define random_iterator_hpp

#include "iterator.hpp"
#include <iterator>
namespace ft
{

	template <typename Iter>
	class my_random_acces_iterator: public ft::iterator<std::random_access_iterator_tag, Iter>
	{

	public:
		/* iterator traits*/
		typedef  Iter 																iterator_type;
		typedef Iter																value_type;
		typedef typename std::random_access_iterator_tag							iterator_category;
		typedef typename ft::iterator<iterator_category, Iter>::difference_type 	difference_type;
		typedef typename ft::iterator<iterator_category, Iter>::pointer 			pointer;
		typedef typename ft::iterator<iterator_category, Iter>::reference 			reference;
		typedef typename ft::iterator<iterator_category,const Iter>::reference  	const_reference;
		/******************/
		/*CONSTRUCTORS*/
		my_random_acces_iterator(void) : current() {
		}
		my_random_acces_iterator(pointer x) : current(x) {}

		template <class U>
		my_random_acces_iterator(const my_random_acces_iterator<U> &obj) : current(obj.base()) {}
		/**************/
		pointer base() const { return current; }
		/*operators*/
		template <class U>
		my_random_acces_iterator &operator=(my_random_acces_iterator<U> const &other){
			current = other.base();
			return *this;
		}
		reference operator*() const { return *current; }
		pointer operator->() const { return current; }
		reference operator[](int n) { return (*(current + n)); }
		const_reference operator[](int n) const { return (*(current + n)); }
		my_random_acces_iterator &operator++()
		{
			++current;
			return *this;
		}
		my_random_acces_iterator operator++(int)
		{
			my_random_acces_iterator tmp(*this);
			++current;
			return tmp;
		}
		my_random_acces_iterator &operator--()
		{
			--current;
			return *this;
		}
		my_random_acces_iterator operator--(int)
		{
			my_random_acces_iterator tmp(*this);
			--current;
			return tmp;
		}
		my_random_acces_iterator operator+=(difference_type i)
		{
			current += i;
			return *this;
		}
		my_random_acces_iterator operator-=(difference_type i)
		{
			current -= i;
			return *this;
		}
		my_random_acces_iterator operator-(difference_type n) const {
			return my_random_acces_iterator(current - n); }
		my_random_acces_iterator operator+(difference_type n) const {
			return my_random_acces_iterator(current + n); }

	protected:
		pointer current;

	};

	template <class Iter1, class Iter2>
	bool operator==(my_random_acces_iterator<Iter1> const &i1, my_random_acces_iterator<Iter2> const &i2) { return i1.base() == i2.base(); }

	template <class Iter1, class Iter2>
	bool operator!=(my_random_acces_iterator<Iter1> const &i1, my_random_acces_iterator<Iter2> const &i2) { return !(i1==i2); }


	template <class Iter1, class Iter2>
	bool operator<(my_random_acces_iterator<Iter1> const &i1, my_random_acces_iterator<Iter2> const &i2) { return i1.base() < i2.base(); }

	template <class Iter1, class Iter2>
	bool operator<=(my_random_acces_iterator<Iter1> const &i1, my_random_acces_iterator<Iter2> const &i2) { return i1.base() <= i2.base(); }

	template <class Iter1, class Iter2>
	bool operator>(my_random_acces_iterator<Iter1> const &i1, my_random_acces_iterator<Iter2> const &i2)
	{
		return i1.base() > i2.base();
		;
	}

	template <class Iter1, class Iter2>
	bool operator>=(my_random_acces_iterator<Iter1> const &i1, my_random_acces_iterator<Iter2> const &i2) { return i1.base() >= i2.base(); }

	template <class Iter>
	my_random_acces_iterator<Iter>
	operator+(typename ft::my_random_acces_iterator<Iter>::difference_type n,
		ft::my_random_acces_iterator<Iter> const &i)
	{
		return my_random_acces_iterator<Iter>(i.base() + n);
	}

	template <class Iter, class Iter2>
	typename my_random_acces_iterator<Iter>::difference_type
	operator-(const ft::my_random_acces_iterator<Iter> &n,
			  const ft::my_random_acces_iterator<Iter2>  &i)
	{
		return n.base() - i.base() ;
	}
}

#endif
