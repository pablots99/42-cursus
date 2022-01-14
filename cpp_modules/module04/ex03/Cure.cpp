/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:25:49 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/14 00:02:43 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}


Cure::Cure(Cure & obj):AMateria(obj)
{
    std::cout << "Cure copy constructor called" << std::endl;

}
Cure &Cure::operator=(Cure &obj)
{
    this->_type = obj._type;
    return *this;
}
AMateria* Cure::clone() const
{
    AMateria *cure = new Cure();
    return cure;
}
void Cure::use(ICharacter& target)
{
    std::cout << "*heals " << target.getName() << " wounds*" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructot called" << std::endl;
}
