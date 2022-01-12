/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:21 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 17:24:41 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    std::cout << "AMateria cnstructor called" << std::endl;
    this->_type = type;
}
std::string const & AMateria::getType() const {
    return this->_type;
}
AMateria::AMateria(AMateria &materia){
    *this = materia;
}

AMateria &AMateria::operator=(AMateria &materia)
{
    this->_type = materia._type;
    return *this;
}

AMateria::~AMateria(){

    std::cout << "AMateria destructor called" << std::endl;
}


void AMateria::use(ICharacter& target){ 
    
}
