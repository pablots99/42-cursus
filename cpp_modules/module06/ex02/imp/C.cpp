/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:07:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 18:19:57 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../def/C.hpp"

C::C() { 
        std::cout << "C constructor called" << std::endl;
}

C::C(C &obj) { 
    *this = obj;
}

C &C::operator=(C &obj) { 
    (void)obj;
    return *this;
}

C::~C(){
    std::cout << "C destructor called" << std::endl;
}