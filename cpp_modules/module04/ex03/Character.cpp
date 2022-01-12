/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:04:59 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 18:12:59 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
{
    this->name = name;
    std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character &obj)
{
    std::cout << "Charactec opy constructor called" << std::endl;

}


Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        if(this->materia[i])
            delete materia[i];
    }
    std::cout << "Characcter destructor called" << std::end;
}