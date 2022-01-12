/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:34:43 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 15:57:59 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    Animal(Animal &animal);
    Animal &operator=(Animal &animal);
    virtual void makeSound() = 0;
    std::string getType();
    virtual ~Animal();
};
#endif
