/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:29:50 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 15:33:02 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"


Dog::Dog(){
    this->_type = "Dog";
    this->brain = new Brain();
    std::cout << "Dog contructor called" << std::endl;
}

Dog::Dog(Dog &dog)
{
    this->brain = new Brain(*dog.brain);
    std::cout << "Dog copy constructor" << std::endl;
    this->_type = dog._type;
}

Dog &Dog::operator=(Dog &animal)
{
    this->_type = animal._type;
    this->brain = new Brain(*animal.brain);
    return *this;
}



void Dog::makeSound(){
    std::cout << "The dog makes wrauff " << std::endl;
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog destructoor called" << std::endl;
}