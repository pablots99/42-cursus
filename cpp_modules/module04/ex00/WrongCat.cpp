/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:43:18 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 19:39:41 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor Called" << std::endl;
}

WrongCat::WrongCat(WrongCat &animal)
{
    *this = animal;
}

WrongCat &WrongCat::operator=(WrongCat &animal)
{
    this->_type = animal._type;
    return *this;
}


void WrongCat::makeSound(){
    std::cout << "The cat makes Wrauff!" << std::endl;
}


WrongCat::~WrongCat() { 
    std::cout << "WrongCat destructor called" << std::endl;
}
