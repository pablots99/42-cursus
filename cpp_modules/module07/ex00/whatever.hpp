/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/18 21:05:06 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	Whatever_HPP
#define Whatever_HPP

#include <iostream>


template<typename T>
void swap(T &a, T &b)
{
    T aux;
    aux = a;
    a = b;
    b = aux;
}

template<typename T>
T const  &min(T const &a, T const &b)
{
    if(a < b)
        return a;
    return b;
}


template<typename T>
T const  &max(T const &a, T const &b)
{
    if(a > b)
        return a;
    return b;
}


#endif

