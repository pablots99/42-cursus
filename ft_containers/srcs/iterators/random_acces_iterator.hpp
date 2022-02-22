/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_acces_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:17:31 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/22 14:43:51 by pablo            ###   ########.fr       */
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
		my_random_acces_iterator() : __t(), current() {}
		explicit my_random_acces_iterator(pointer x) : __t(x), current(x) {}

		template <class U>
		my_random_acces_iterator(const my_random_acces_iterator<U> &obj) :
			__t((pointer)obj.base()), current((pointer)obj.base()) {}
		/**************/


		pointer base() const { return current; }
		/*operators*/
		template <class U>
		my_random_acces_iterator &operator=(const my_random_acces_iterator<U> &other)
		{
			current = other.base();
			return *this;
		}
		reference operator*() const { return *current; }
		pointer operator->() const { return std::addressof(operator*()); }
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
		/*cange to non member*/
		my_random_acces_iterator operator-(difference_type n) const { return my_random_acces_iterator(current - n); }
		my_random_acces_iterator operator+(difference_type n) const { return my_random_acces_iterator(current + n); }
		difference_type operator-(my_random_acces_iterator n) const { return current - n.base(); }
		difference_type operator+(my_random_acces_iterator n) const { return current + n.base(); }
		bool operator==(my_random_acces_iterator const &i2) { return current == i2.base(); }
		bool operator!=(my_random_acces_iterator const &i2) { return current != i2.base(); }
	private:
		pointer __t;
		pointer current;

	protected:
	};

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
	my_random_acces_iterator<Iter> operator+(typename ft::my_random_acces_iterator<Iter>::difference_type n, ft::my_random_acces_iterator<Iter> const &i)
	{
		return my_random_acces_iterator<Iter>(i.base() + n);
	}
	template <class Iter>
	my_random_acces_iterator<Iter> operator-(typename ft::my_random_acces_iterator<Iter>::difference_type n, my_random_acces_iterator<Iter> const &i)
	{
		return my_random_acces_iterator<Iter>(i.base() - n);
	}
}

#endif
