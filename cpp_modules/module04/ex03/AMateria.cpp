/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:21 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/14 02:37:29 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
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
	materia._type = materia._type;
    return *this;
}

AMateria::~AMateria(){
    std::cout << "AMateria destructor called" << std::endl;
}


void AMateria::use(ICharacter& target){
	    std::cout << "Materia interacts with " << target.getName() << std::endl;
}
