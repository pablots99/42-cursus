/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:58:17 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 19:41:46 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(){
    this->_type = "";
    std::cout << "Wrong animal coonstructor called" << std::endl;
}


void WrongAnimal::makeSound()
{
    std::cout << "Wrong sound!" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &animal)
{
    *this = animal;
}

std::string WrongAnimal::getType() { 
    return this->_type;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &animal)
{
    this->_type = animal._type;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "wrong animal destructor called" << std::endl;
}