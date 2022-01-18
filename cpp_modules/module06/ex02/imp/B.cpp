/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:07:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 18:28:45 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../def/B.hpp"

B::B() { 
        std::cout << "B constructor called" << std::endl;

}

B::B(B &obj) { 
    *this = obj;
}

B &B::operator=(B &obj) { 
    (void)obj;
    return *this;
}

B::~B(){
        std::cout << "B destructor called" << std::endl;

}