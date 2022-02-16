/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:29 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/16 17:08:22 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>
#include "../iterators/iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils.hpp"


#include <iterator>

#include <type_traits>

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T 												value_type;
		typedef Allocator 										allocator_type;
		typedef value_type 										&reference;
		typedef const value_type 								&const_reference;
		typedef value_type 										*pointer;
		typedef const value_type 								const_pointer;
		typedef const ptrdiff_t 								difference_type;
		typedef  size_t											size_type;
		typedef ft::my_random_acces_iterator<value_type> 		iterator;
		typedef ft::my_random_acces_iterator<const value_type> 	const_iterator;
		typedef ft::reverse_iterator<iterator> 					reverse_iterator;
		typedef ft::reverse_iterator<const iterator> 			const_reverse_iterator;

		/*CONSTRUCTORS*/
		vector() :_begin(nullptr), _size(0),_capacity(0){} //defaul
		explicit vector (size_type n, const value_type& val):_size(0),_capacity(0){assign(n,val);} //fill
		template <class InputIterator>
        vector (InputIterator first, InputIterator last):_size(0),_capacity(0){assign(first,last);}//range
		vector (const vector& x):_size(0),_capacity(0) {
			this->reserve(x.capacity());
			this->_size = x.size();
			if(_size)
				std::copy(x.begin(), x.begin() + x.size(), this->_begin);
		}//copy
		vector(value_type val): _begin(0),_size(0),_capacity(0) { 
			reserve(1);
			_allocator.construct(_begin,val);
			_size++;
		}


		/*ITERATORS*/
		iterator		begin(void){return iterator(_begin);}
		const_iterator	begin(void) const { return const_iterator(_begin); }

		iterator		end() { return iterator(&_begin[_size]); }
		const_iterator	end() const { return const_iterator(&_begin[_size]); }

		reverse_iterator		rbegin() {return reverse_iterator(this->end());};
		const_reverse_iterator	rbegin() const {return const_reverse_iterator(this->end());};

		reverse_iterator 		rend() {return reverse_iterator(this->begin());};
		const_reverse_iterator	rend() const {return const_reverse_iterator(this->end());}

		/*CAPACITY*/
		size_type size() const { return _size;}
		size_type max_size() const {return ((4294967296) / sizeof(value_type) - 1);} // it is not done
		void reserve (size_type n)
		{
			if(n < _capacity)
				return ;
			pointer aux;
			aux = _allocator.allocate(n + 1);
			if(_size)
			{
				std::copy(_begin, _begin + _size, aux);
				_allocator.deallocate(_begin,_capacity);
			}
			_capacity = n;
			_begin = aux;
		}
		void resize(size_type n, value_type val) {
			pointer aux;
			if(n < _size) {
				aux = _allocator.allocate(n);
				_capacity = n;
				std::copy(_begin, _begin + n, aux);
				//destroy
				destroy_begin();
				_allocator.deallocate(_begin,_size);
				_begin = aux;
				_size = n;
			}
			else
			{
				if (n > _capacity){
					_capacity *= 2;
					aux = _allocator.allocate(_capacity);
					std::copy(_begin, _begin + _size, aux);
					//destroy
					destroy_begin();
					_allocator.deallocate(_begin,_size);
					_begin = aux;
				}
				_allocator.construct(_begin + _size, val);
				_size++;
			}
		}
		size_type capacity() const{return _capacity;};
		bool empty() const {return (_size == 0);};


		/*ELEMENT ACCESS*/
		reference at (size_type n) {
			if(n >= _size)
				throw std::out_of_range("Vector index out of range");
			return (*(_begin + n));
		}
		const_reference back() const { 
			return at(_size - 1);
		};
		reference front() { 
			return at(0);
		}
		const_reference front() const { 
			return at(0);
		};
		reference back() { 
			return at(_size - 1);
		}
		
		reference operator[](int n){return (*(_begin + n));}
		
		const_reference at (size_type n) const {
			if(n >= _size)
				throw std::out_of_range("Vector index out of range");
			return (*(_begin + n));
		}

		/*MODIFIERS*/
		void assign (size_type n, const value_type& val) {
			uncreate();
			_size = 0;
			_capacity = 0;
			reserve(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_begin + i,val);
			_size = n;
		}

		//cange enable if to ENABLE IF ITERATOR!!!!!!!
		template <typename InputIterator, std::enable_if<!std::is_integral<InputIterator>::value, bool> >
  		void assign (InputIterator first, InputIterator last) {
			  iterator f = iterator(&*first);
			  iterator l = iterator(&*last);
			  size_t len = ft::distance(f,l);
			  uncreate();
			  this->reserve(len + 2);
			  pointer p = f.base();
			  for (size_t i = 0; i < len; i++){
				  this->_allocator.construct(_begin + i,*p);
				  p++;
			  }
			 _size = len;
		}

	
		void push_back (const value_type& val)
		{
			if(!(_size < _capacity))
				reserve(_size * 2);
			_allocator.construct(_begin + _size, val);
			_size++;
		}
		void pop_back() {
			if(!_size)
				return ;
			_allocator.destroy(&_begin[_size - 1]);
			_size--;
		}
	iterator insert (iterator position, const value_type& val)
	{
		size_t last_size = _size;
		pointer pos = position.base();
		pointer res = _allocator.allocate(_size + 1);
		size_t len = ft::distance(_begin, pos);
		std::copy(_begin, pos - 1, res);
		this->uncreate();
		_allocator.construct(res + len - 1, val);
		_size++;
		for (size_t i = len; i < _size; i++)
		{
			_allocator.construct(res + i, val);
			res++;
		}
		_begin = res;
		_size  = last_size + 1;
		return iterator(_begin + len);
	}

	// void insert (iterator position, size_type n, const value_type& val)
	// {

	// }

	// template <class InputIterator>
    // void insert (iterator position, InputIterator first, InputIterator last)
	// {

	// }
	private:
		pointer _begin;
		allocator_type _allocator;
		size_t _size;
		size_t _capacity;



		void destroy_begin() {
			for (size_t i = 0; i < _size; i++)
				_allocator.destroy(_begin + _size);
		}
		void uncreate(){
			if(!_capacity)
				return ;
			destroy_begin();
			_allocator.deallocate(_begin,_size);
			_size = 0;
			_capacity = 0;
		}

	};
}
#endif
