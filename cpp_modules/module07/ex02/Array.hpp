/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:24:32 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/19 16:09:39 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>


template<typename T>
void  copy(T &dest, T&  start, int len){
    for (int i = 0; i < len; i++)
    {
        dest[i] = start[i];
    }
}


template<typename T>
class Array 
{
    class OutOfIndexException: public std::exception{
        const char * what() const throw() { 
            return "The element is out of limits";
        }
    };

    private:
        const int _length;
        T * _arr;
    public:
        Array():_length(0),_arr(NULL){};
        Array(unsigned int n):_length(n)
        {
            if(n < 0)
                throw OutOfIndexException();
            _arr = new T[n];
        }
        Array(Array *obj):_arr(new T[obj->_length])
        {
            copy(*this,obj,this->_length);
        }
        Array & operator=(Array &obj){
            copy(*this,obj,this->_length);
            return *this;
        }
        int size() const  { return _length;}
        T & operator[](int i){ 
            if ( i > _length -1 || i < 0 )
                throw OutOfIndexException();
            return _arr[i];
        }
        ~Array(){
            if(_length)
                delete [] _arr;
        }
};



#endif