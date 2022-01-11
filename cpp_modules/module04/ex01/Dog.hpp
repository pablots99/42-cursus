/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:42:49 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 21:16:58 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
#define DOG_HPP


#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal 
{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(Dog &dog);
        Dog &operator=(Dog &animal);
        void makeSound();
        ~Dog();
};

#endif