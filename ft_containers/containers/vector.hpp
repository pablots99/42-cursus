/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:29 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/20 19:36:02 by ptorres          ###   ########.fr       */
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
		//default
		vector(const allocator_type alloc =  allocator_type()) : _begin(NULL), _size(0), _capacity(0),_allocator(alloc){}

		//fill
		explicit vector(const size_type n, const value_type &val = value_type(), const allocator_type alloc = allocator_type()) :_begin(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			assign(n, val);
		}

		//range
		template <class InputIterator>
		vector(InputIterator first, InputIterator last,const allocator_type alloc = allocator_type()) : _size(0), _capacity(0) ,_allocator(alloc)
		{
			assign(first, last);
		}

		//copy
		vector(const vector &x) : _begin(NULL), _size(0), _capacity(0)
		{
			_allocator = x.get_allocator();
			assign(x.begin(),x.end());
			// _allocator = x.get_allocator();
			// this->reserve(x.size());
			// if (_size)
			// 	ft::copy(x.begin(), x.begin() + x.size(), this->_begin);
		}
		
		~vector()
		{
			uncreate();
		}

		vector &operator=(const vector& obj) {
			this->uncreate();
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
		size_type max_size() const 
		{ 
			return ft::min<size_type>(allocator_type().max_size(), std::numeric_limits<difference_type>::max());
		}
		allocator_type get_allocator() const { return allocator_type(); }
		void reserve(size_type n)
		{
			pointer aux;

			aux = NULL;
			if (n < _capacity)
				return;
			if (n > max_size())
				throw std::length_error("vector::reserve");
			aux = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(aux + i);
			
			if (_size)
			{
				ft::copy(this->begin(), this->end(), aux);
				_allocator.deallocate(_begin, _capacity);
			}
			_capacity = n;
			_begin = aux;
		}

		void resize(size_type n, value_type val = value_type())
		{
			// if (n > _size)
			// {
			// 	std::cout << "insert" << std::endl;
    		// 	this->insert(end(), n - _size, val);
			// }
			// else if (n < size())
			// {
			// 	std::cout << "erase" << std::endl;
    		// 	this->erase(begin() + n , end());
			// }
			pointer aux;
			int s;
			if (n < _size)
			{
				s = _capacity;
				aux = _allocator.allocate(s);
				for (int i = 0; i < s; i++)
					_allocator.construct(aux + i);
				ft::copy(_begin, _begin + n, aux);
				this->uncreate();
				_capacity = s;
				_begin = aux;
				_size = n;
			}
			else
			{
				if (n > _capacity)
				{
					if (n > _capacity * 2)
						reserve(n);
					else
						reserve(_capacity * 2);
				}
				
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
			if (n > _capacity)
			{
				uncreate();
				_size = 0;
				_capacity = 0;
				this->reserve(n);
			}
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_begin + i, val);
			_size = n;
		}

		template <typename InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		assign(InputIterator first, InputIterator last)
		{
			size_t len = ft::distance(first, last);
			if (len > _capacity)
			{
				uncreate();
				this->reserve(len);
			}
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
			size_t n_capacity = _capacity;
			if (_size >= _capacity)
				n_capacity = _capacity * 2;
			pointer res = _allocator.allocate(n_capacity);
			for (size_t i = 0; i < n_capacity; i++)
				_allocator.construct(res + i);
			size_t len = ft::distance(this->begin(), position);
			ft::copy(_begin, _begin + len, res);
			_allocator.construct(res + len, val);
			ft::copy(_begin + len, _begin + last_size, res + len + 1);
			this->uncreate();
			_begin = res;
			_size = last_size + 1;
			_capacity = n_capacity;
			return iterator(&_begin[len]);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_t last_size = _size;
			// size_t c = _capacity;
			pointer res = _allocator.allocate(_size + n);
			size_t len = ft::distance(this->begin(), position);
			ft::copy(_begin, _begin + len, res);
			for (size_t i = 0; i < n; i++)
				_allocator.construct(res + len + i, val);
			ft::copy(_begin + len, _begin + last_size, res + len + n);
			this->uncreate();
			_begin = res;
			_size = last_size + n;
			_capacity = last_size + n;
		}

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(iterator position, InputIterator first, InputIterator last)
		{
			size_t last_size = _size;
			size_t i;
			size_t len2 = ft::distance(first, last);
			pointer res = _allocator.allocate(_size + len2);
			size_t len = ft::distance(this->begin(), position);
			ft::copy(_begin, _begin + len, res);
			for (i = 0; i < len2; i++)
			{
				_allocator.construct(res + len + i, *first);
				first++;
			}
			ft::copy(_begin + len, _begin + last_size, res + len + i);
			this->uncreate();
			_begin = res;
			_size = last_size + len2;
			_capacity = last_size + len2;
		}

		iterator erase(iterator position)
		{
			size_t last_size = _size;
			size_t last_cap = _capacity + 2;
			pointer res = _allocator.allocate(last_cap);
			size_t len = ft::distance(this->begin(), position);
			ft::copy(_begin, _begin + len, res);
			_allocator.destroy(_begin + len);
			ft::copy(_begin + len + 1, _begin + _size, res + len);
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
			ft::copy(_begin, _begin + len, res);
			// size_t i;
			// for (i = 0; i < len2; i++)
			// 	_allocator.destroy(_begin + len + i);
			//this->uncreate();
 
			ft::copy(_begin + len + len2, _begin + last_size, res + len);
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
			for (size_t i = 0; i < _capacity; i++)
				_allocator.destroy(_begin + _size);
		}
		void uncreate()
		{
			if (!_capacity)
				return;
			//destroy_begin();
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

}// namespace ft
#endif
