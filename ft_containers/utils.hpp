/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:48:05 by ptorres           #+#    #+#             */
/*   Updated: 2022/05/13 15:46:19 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "iterators/iterator.hpp"

namespace ft
{

	/*
	 *enable_if:
	 *Is used fo the deduction for invalid types
	 *right in the declaration of a template
	 *is usefull when choosing an overload on a template class
	 *doc:https://eli.thegreenplace.net/2014/sfinae-and-enable_if/
	 */
	template <bool, typename T = void>
	struct enable_if
	{
	};
	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};


	/*
		chck if is is const
	*/

	template<bool b, typename T>
	struct is_const_st {
		typedef T type;
		static const bool value = b;
	};
	struct is_const : is_const_st<true, bool> { };

	/*
	 *is_integral:
	 *Checks whether T is an integral type
	 *integral types:
	 *bool, char, char16_t, char32_t, wchar_t, short, int, long, long long
	 */
	template <bool b, typename T>
	struct is_integral_st
	{
		typedef T type;
		static const bool value = b;
	};
	template <class T>
	struct is_integral : public is_integral_st<false, bool>
	{
	};
	template <>
	struct is_integral<bool> : public is_integral_st<true, bool>
	{
	};
	template <>
	struct is_integral<char> : public is_integral_st<true, char>
	{
	};
	// template <>
	// struct is_integral<char16_t> : public is_integral_st<true, char16_t>
	// {
	// };
	// template <>
	// struct is_integral<char32_t> : public is_integral_st<true, char32_t>
	// {
	// };
	template <>
	struct is_integral<wchar_t> : public is_integral_st<true, wchar_t>
	{
	};
	template <>
	struct is_integral<signed char> : public is_integral_st<true, signed char>
	{
	};
	template <>
	struct is_integral<short int> : public is_integral_st<true, short int>
	{
	};
	template <>
	struct is_integral<int> : public is_integral_st<true, int>
	{
	};
	template <>
	struct is_integral<long int> : public is_integral_st<true, long int>
	{
	};
	template <>
	struct is_integral<long long int> : public is_integral_st<true, long long int>
	{
	};
	template <>
	struct is_integral<unsigned char> : public is_integral_st<true, unsigned char>
	{
	};
	template <>
	struct is_integral<unsigned short int> : public is_integral_st<true, unsigned short int>
	{
	};
	template <>
	struct is_integral<unsigned int> : public is_integral_st<true, unsigned int>
	{
	};

	/*
	 *lexicographical_compare(algorithm):
	 *compare to iterator ranges until one element is not equivalent to the other,
	 *If both sequences compare equal until one of them ends,
	 *the shorter sequence is lexicographically less than the longer one.
	 */
	template <class Iterator1, class Iterator2>
	bool lexicographical_compare(Iterator1 start1, Iterator1 end1, Iterator2 start2, Iterator2 end2)
	{
		while (start1 != end1 && start2 != end2)
		{
			if (*start2 < *start1)
				return false;
			else if (*start1 < *start2)
				return true;
			++start1;
			++start2;
		}
		return (start2 != end2) && (start1 == end1);
	}

	/*
		COPY FRON FIRST TO LAST INTO D_FIRST
	*/
	template <class InputIt, class OutputIt>
	OutputIt copy(InputIt first, InputIt last, OutputIt d_first)
	{
		for (; first != last; (void)++first, (void)++d_first)
		{
			*d_first = *first;
		}
		return d_first;
	}

	/*

		DISTANCE BETWEEN FIRST AND LAST

	*/
	template <class Iter>
	const typename ft::iterator_traits<Iter>::difference_type
	aux_distance(Iter first, Iter last, std::input_iterator_tag)
	{
		typename std::iterator_traits<Iter>::difference_type result = 0;
		while (first != last)
		{
			++first;
			++result;
		}
		return result;
	}
	template <class Iter>
	const typename std::iterator_traits<Iter>::difference_type
	distance(Iter first, Iter last)
	{
		return aux_distance(first, last, typename ft::iterator_traits<Iter>::iterator_category());
	}

	/*pair:
	 * is a class template that provides a way to store two heterogeneous objects as a single unit
	 */
	template <class T1, class T2>
	struct pair
	{
		/*types*/
		typedef T1 first_type;
		typedef T2 second_type;
		/*objects*/
		T1 first;
		T2 second;
		/*member fuctions*/
		pair() : first(), second() {}
		pair(T1 const &t1, T2 const &t2) : first(t1), second(t2) {}
		template <class U1, class U2>
		pair(const pair<U1, U2> &p) : first(p.first), second(p.second) {}

		pair &operator=(pair const &p)
		{
			first = p.first;
			second = p.second;
			return *this;
		}
	};
	/*pair non member functions*/
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 &t, T2 &u) { return new pair<T1, T2>(t, u); };

	/*operators*/
	template <class T1, class T2>
	bool operator==(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
	{
		return ((p1.first == p2.first) && (p1.second == p2.second));
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
	{
		return !(p1 == p2);
	}
	template <class T1, class T2>
	bool operator<(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
	{
		return ((!(p1.first < p2.first) && (p1.second < p2.second)) || (p1.first < p2.first));
	}

	template <class T1, class T2>
	bool operator>(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
	{
		return p2 < p1;
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
	{
		return !(p1 < p2);
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1, T2> &p1, const pair<T1, T2> &p2)
	{
		return !(p1 > p2);
	}
	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (ft::pair<T1, T2>(x, y));
	}

}

#endif
