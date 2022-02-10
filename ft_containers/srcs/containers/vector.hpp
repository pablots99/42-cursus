/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:29 by ptorres           #+#    #+#             */
/*   Updated: 2022/02/10 17:50:50 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP  
#define FT_VECTOR_HPP  
#include <iostream>
#include "../iterators/iterator.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"


namespace ft { 
    template<class T, class Allocator = std::allocator<T> >
    class vector {
        public:
            typedef T                                                                value_type;
            typedef Allocator                                                        allocator_type;
            /*allocator*/
            typedef  value_type&                                                     reference;
            typedef  const value_type&                                               const_reference;
            typedef  value_type                                                      *pointer;
            typedef  const value_type                                                const_pointer;
            typedef  const ptrdiff_t                                                 difference_type;
            //allocator_type::difference_type see if matters usig allocator_type as in the definition of the vector
            /*vectory iterators*/
            //typedef ft::my_random_acces_iterator<value_type>                        iterator;
            // typedef ft::my_random_acces_iterator<cosnt value_type>                  const_iterator;
            typedef std::__wrap_iter<value_type>                                    iterator;
            typedef std::__wrap_iter<const value_type>                              const_iterator;
            typedef ft::reverse_iterator<iterator>                                  reverse_iterator;
            typedef ft::reverse_iterator<const iterator>                            const_reverse_iterator;
            /*CONSTRUCTORS*/
            /*default*/
            vector ():_begin(nullptr),_end(nullptr),_size(0){
                std::cout << "vector default constructor"  << std::endl;
            }

            /*MEMBER FUNCTIONS*/
            //ESTO SE RALL MAZOOOOO
            //iterator begin(void){return iterator(_begin);}
            pointer begin(){return _begin;}
            const_iterator begin(void) const {return const_iterator(_begin);}
            //&begin[_size]
            iterator end(){return iterator(_begin);}
            const_iterator end() const{return const_iterator(_begin);}
            void push_back (const value_type& val) {
                   int i = 0;
                   pointer *aux = &_begin;
                    while(_begin != _end) {
                        std::cout << *_begin << std::endl;
                        _begin++;
                        i++;
                    }
                   _begin = _allocator.allocate(1);
                   this->_allocator.construct(_begin,val);
                   this->_end = _begin;
                   _begin = *aux;
            }
        private:
              pointer           _begin;
              allocator_type    _allocator;
              pointer           _end;
              pointer           _size;
    };
}
#endif
