/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:36:32 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:42:33 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "./vector.hpp"


namespace ft {
    template<class T, class Container = ft::vector<T> >
    class stack {

        public:
            typedef Container                               container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;


            stack (const container_type& ctnr = container_type()): c(ctnr) {}

            bool empty() const { return c.empty(); }
            size_type size() const { return c.size(); }
            value_type& top() { return c.back(); }
            const value_type& top() const { return c.back(); }
            void push(const value_type& x) { c.push_back(x); }
            void pop() { c.pop_back(); }

        protected:
            container_type c;


        template <class T1, class Container1>
        friend bool operator==(const ft::stack<T1, Container1>& x,const ft::stack<T1, Container1>& y);

        template <class T1, class Container1>
        friend bool operator<(const ft::stack<T1, Container1>& x,const ft::stack<T1, Container1>& y);

    };

    template <class T, class Container>
    bool operator==(const ft::stack<T, Container>& x,const ft::stack<T, Container>& y){
             return (x.c == y.c);
    }

    template <class T, class Container>
    bool operator!=(const ft::stack<T, Container>& x,const ft::stack<T, Container>& y){
            return !(x == y);
    }

    template <class T, class Container>
    bool operator<(const ft::stack<T, Container>& x,const ft::stack<T, Container>& y){
            return (x.c < y.c);
    }

    template <class T, class Container>
    bool operator>=(const ft::stack<T, Container>& x,const ft::stack<T, Container>& y){
            return !(x < y);
    }

    template <class T, class Container>
    bool operator>(const ft::stack<T, Container>& x,const ft::stack<T, Container>& y){
            return !(x < y) && (x != y);
    }


    template <class T, class Container>
    bool operator<=(const ft::stack<T, Container>& x,const ft::stack<T, Container>& y){
            return !(x > y);
    }



}

#endif
