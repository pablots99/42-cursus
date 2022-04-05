/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:29 by ptorres           #+#    #+#             */
/*   Updated: 2022/04/05 15:59:48 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
#define FT_VECTOR_HPP
#include <iostream>
#include "../iterators/random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../utils.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef value_type *pointer;
		typedef const value_type const_pointer;
		typedef const ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef ft::my_random_acces_iterator<value_type> iterator;
		typedef ft::my_random_acces_iterator<value_type const> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator< const_iterator>  const_reverse_iterator;

		/*CONSTRUCTORS*/
		vector(const allocator_type alloc = allocator_type()) : _begin(NULL), _size(0), _capacity(0),_allocator(alloc){}
		//defaul
		explicit vector(const size_type n, const value_type &val = value_type(), const allocator_type alloc = allocator_type()) :_begin(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			assign(n, val);
		} //fill

		template <class InputIterator>
		vector(InputIterator first, InputIterator last,const allocator_type alloc = allocator_type()) : _size(0), _capacity(0) ,_allocator(alloc)
		{
			assign(first, last);
		} //range

		vector(const vector &x) : _size(0), _capacity(0)
		{
			this->reserve(x.capacity());
			this->_size = x.size();
			if (_size)
				std::copy(x.begin(), x.begin() + x.size(), this->_begin);
		} //copy
		vector &operator=(const vector& obj) {
			uncreate();
			this->assign(obj.begin(),obj.end());
			return *this;
		}
		/*ITERATORS*/
		iterator begin(void) { return iterator(_begin); }
		const_iterator begin(void) const { return const_iterator(_begin); }

		iterator end() { return iterator(&_begin[_size]); }
		const_iterator end() const { return const_iterator(&_begin[_size]); }

		reverse_iterator rbegin() { return reverse_iterator(this->end()); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); };

		reverse_iterator rend() { return reverse_iterator(this->begin()); };
		const_reverse_iterator rend() const { return const_reverse_iterator(this->end()); }

		/*CAPACITY*/
		size_type size() const { return _size; }
		size_type max_size() const { return _allocator.max_size(); } // it is not done
		void reserve(size_type n)
		{
			if (n < _capacity)
				return;
			if (n > max_size())
				return;
			pointer aux;
			aux = _allocator.allocate(n + 1);
			if (_size)
			{
				std::copy(_begin, _begin + _size, aux);
				_allocator.deallocate(_begin, _capacity);
			}
			_capacity = n;
			_begin = aux;
		}

		void resize(size_type n, value_type val = value_type())
		{
			pointer aux;
			if (n < _size)
			{
				aux = _allocator.allocate(n);
				std::copy(_begin, _begin + n, aux);
				this->uncreate();
				_capacity = n;
				_begin = aux;
				_size = n;
			}
			else
			{
				reserve(n);
				for (size_type i = _size; i < n; i++)
					*(_begin + i) = val;
				_size = n;
			}
		}
		size_type capacity() const { return _capacity; };
		bool empty() const { return (_size == 0); };

		/*ELEMENT ACCESS*/
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("Vector index out of range");
			return (*(_begin + n));
		}
		const_reference back() const
		{
			return at(_size - 1);
		};
		reference front()
		{
			return at(0);
		}
		const_reference front() const
		{
			return at(0);
		};
		reference back()
		{
			return at(_size - 1);
		}

		reference operator[](int n)const { return (*(_begin + n)); }

		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("Vector index out of range");
			return (*(_begin + n));
		}

		/*MODIFIERS*/
		void assign(size_type n, const value_type &val)
		{
			uncreate();
			_size = 0;
			_capacity = 0;
			reserve(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_begin + i, val);
			_size = n;
		}

		template <typename InputIterator>
		typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type
		assign(InputIterator first, InputIterator last)
		{
			size_t len = ft::distance(first, last);
			uncreate();
			this->reserve(len + 2);
			for (size_t i = 0; i < len; i++)
			{
				this->_allocator.construct(_begin + i, *first);
				first++;
			}
			_size = len;
		}

		void push_back(const value_type &val)
		{
			if(_size == 0 && _capacity == 0)
				reserve(1);
			if (!(_size < _capacity))
				reserve(_size * 2);
			_allocator.construct(_begin + _size, val);
			_size++;
		}
		void pop_back()
		{
			if (!_size)
				return;
			_allocator.destroy(&_begin[_size - 1]);
			_size--;
		}

		void clear()
		{
			this->destroy_begin();
			_size = 0;
		}

		iterator insert(iterator position, const value_type &val)
		{
			size_t last_size = _size;
			pointer res = _allocator.allocate(_size + 2);
			size_t len = ft::distance(this->begin(), position);
			std::copy(_begin, _begin + len, res);
			_allocator.construct(res + len, val);
			std::copy(_begin + len, _begin + last_size, res + len + 1);
			this->uncreate();
			_begin = res;
			_size = last_size + 1;
			_capacity = last_size + 2;
			return iterator(&_begin[len]);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_t last_size = _size;
			pointer res = _allocator.allocate(_size + n + 1);
			size_t len = ft::distance(this->begin(), position);
			std::copy(_begin, _begin + len, res);
			for (size_t i = 0; i < n; i++)
				_allocator.construct(res + len + i, val);
			std::copy(_begin + len, _begin + last_size, res + len + n);
			this->uncreate();
			_begin = res;
			_size = last_size + n;
			_capacity = last_size + n + 1;
		}

		template <class InputIterator>
		typename std::enable_if<!std::is_integral<InputIterator>::value, void>::type
		insert(iterator position, InputIterator first, InputIterator last)
		{
			size_t last_size = _size;
			size_t len2 = ft::distance(first, last);
			pointer res = _allocator.allocate(_size + len2 + 1);
			size_t len = ft::distance(this->begin(), position);
			std::copy(_begin, _begin + len, res);
			for (size_t i = 0; i < len2; i++)
			{
				_allocator.construct(res + len + i, *first);
				first++;
			}
			this->uncreate();
			std::copy(_begin + len, _begin + last_size, res + len + len2);
			_begin = res;
			_size = last_size + len2;
			_capacity = last_size + len2 + 1;
		}

		iterator erase(iterator position)
		{
			size_t last_size = _size;
			size_t last_cap = _capacity + 2;
			pointer res = _allocator.allocate(last_cap);
			size_t len = ft::distance(this->begin(), position);
			std::copy(_begin, _begin + len, res);
			_allocator.destroy(_begin + len);
			std::copy(_begin + len + 1, _begin + _size, res + len);
			this->uncreate();
			_begin = res;
			_size = last_size - 1;
			_capacity = last_cap;
			return iterator(&_begin[len]);
		}

		iterator erase(iterator first, iterator last)
		{
			size_t last_size = _size;
			size_t last_cap = _capacity;
			size_t len2 = ft::distance(first, last);
			pointer res = _allocator.allocate(_capacity);
			size_t len = ft::distance(this->begin(), first);
			std::copy(_begin, _begin + len, res);
			size_t i;
			for (i = 0; i < len2; i++)
				_allocator.destroy(_begin + len + i);
			this->uncreate();
			std::copy(_begin + len + i, _begin + last_size, res + len);
			_begin = res;
			_size = last_size - len2;
			_capacity = last_cap;
			return iterator(&_begin[len]);
		}
		void swap( vector& other ) {
			pointer p = other._begin;
			allocator_type alloc = other._allocator;
			size_t s = other._size;
			size_t c = other._capacity;
			other._begin = this->_begin;
			other._allocator = this->_allocator;
			other._size = this->_size;
			other._capacity = this->_capacity;
			this->_begin = p;
			this->_allocator = alloc;
			this->_size = s;
			this->_capacity = c;
		}

	protected:
		pointer _begin;
		size_t _size;
		size_t _capacity;
		allocator_type _allocator;

		void destroy_begin()
		{
			for (size_t i = 0; i < _size; i++)
				_allocator.destroy(_begin + _size);
		}
		void uncreate()
		{
			if (!_capacity)
				return;
			destroy_begin();
			_allocator.deallocate(_begin, _size);
			_size = 0;
			_capacity = 0;
		}
	};
	template< class T >
	bool operator==( const ft::vector<T>& lhs,
					const ft::vector<T>& rhs )
	{
		size_t i = 0;
		if(lhs.size() != rhs.size())
			return false;
		while (lhs[i] == rhs[i]  && i < lhs.size())
			i++;
		return (i == lhs.size());
	}


	template< class T>
	bool operator!=( const ft::vector<T>& lhs,
					const ft::vector<T>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T>
	bool operator<( const ft::vector<T>& lhs,
					const ft::vector<T>& rhs )
	{
		return ft::lexicographical_compare(lhs.begin(),lhs.end(),rhs.begin(),rhs.end ());

	}

	template< class T>
	bool operator>( const ft::vector<T>& lhs,
					const ft::vector<T>& rhs )
	{
		return (rhs < lhs);
	}

	template< class T >
	bool operator<=( const ft::vector<T>& lhs,
					const ft::vector<T>& rhs )
	{
		return !(lhs > rhs);
	}

	template< class T>
	bool operator>=( const ft::vector<T>& lhs,
					const ft::vector<T>& rhs )
	{
		return !(lhs < rhs);
	}
	template <class T>
	void swap (vector<T>& x, vector<T>& y)
	{
		x.swap(y);
	}

};// namespace ft
#endif
