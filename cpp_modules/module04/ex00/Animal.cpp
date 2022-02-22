/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:39:39 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 16:36:22 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal() {
    this->_type  = "";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal &animal)
{
    std::cout << "Animal constructor called" << std::endl;
    *this = animal;
}

void Animal::makeSound(){
    
}

std::string Animal::getType(){
    return _type;
}

Animal::~Animal() { 
    std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal &animal) {
    this->_type = animal.getType();
    return *this;
}

