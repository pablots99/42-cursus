/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:42:49 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 14:50:28 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP


#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal 
{
    public:
        Dog();
        Dog(Dog &dog);
        Dog &operator=(Dog &animal);
        void makeSound();
        Brain *brain;
        ~Dog();
};

#endif