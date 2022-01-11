/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:29:50 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 21:17:42 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(){
    this->_type = "Dog";
    this->_brain = new Brain();
    std::cout << "Dog contructor called" << std::endl;
}

Dog::Dog(Dog &dog)
{
    *this = dog;
}

Dog &Dog::operator=(Dog &animal)
{
    this->_type = animal._type;
    return *this;
}



void Dog::makeSound(){
    std::cout << "The dog makes wrauff " << std::endl;
}

Dog::~Dog(){
    std::cout << "Dog destructoor called" << std::endl;
}