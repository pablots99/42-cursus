/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:07:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 18:28:47 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../def/A.hpp"

A::A() { 
    std::cout << "A constructor called" << std::endl;
}

A::A(A &obj) { 
    *this = obj;
}

A &A::operator=(A &obj) { 
    (void)obj;
    return *this;
}

A::~A(){
            std::cout << "A destructor called" << std::endl;

}