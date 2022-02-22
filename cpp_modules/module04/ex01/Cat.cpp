/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:39:22 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 15:44:19 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->brain = new Brain();
    std::cout << "Cat constructor Called" << std::endl;
}
Cat::Cat(Cat &cat)
{
    this->brain = new Brain(*cat.brain);
    std::cout << "Cat copy constructor" << std::endl;
    this->_type = cat._type;
}

Cat &Cat::operator=(Cat &animal)
{
    this->_type = animal._type;
    this->brain = new Brain(*animal.brain);
    return *this;
}

void Cat::makeSound(){
    std::cout << "The cat make miauuu!" << std::endl;
}

Cat::~Cat() { 
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}
