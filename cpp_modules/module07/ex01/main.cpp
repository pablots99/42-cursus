/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 21:07:05 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/19 13:22:50 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <ostream>


template< typename T > 
void print( T const & num ) 
{ 
    std::cout << num << std::endl; 
}



int main() { 
    int nums[] = { 0,1,2,3,4,6,7,8,9,10 };
    iter( nums, 10, print ); 

    return 0; 
}