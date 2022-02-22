/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:07:03 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/19 13:20:43 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>



template<typename T>
void iter(T*  arr,int len, void (*f)(const T &))
{
    for (int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}


#endif