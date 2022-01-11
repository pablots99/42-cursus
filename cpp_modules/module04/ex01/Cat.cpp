/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:39:22 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 21:17:32 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat()
{
    this->_type = "Cat";
    this->_brain = new Brain();
    std::cout << "Cat constructor Called" << std::endl;
}

Cat::Cat(Cat &cat)
{
    *this = cat;
}

Cat &Cat::operator=(Cat &animal)
{
    this->_type = animal._type;
    return *this;
}

void Cat::makeSound(){
    std::cout << "The cat make miauuu!" << std::endl;
}

Cat::~Cat() { 
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
}
