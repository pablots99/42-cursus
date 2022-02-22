/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:01:39 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 02:31:18 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:25:49 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/14 00:00:23 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"


Ice::Ice():AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}


Ice::Ice(Ice & obj):AMateria(obj)
{
    std::cout << "Ice copy constructor called" << std::endl;

}
Ice &Ice::operator=(Ice &obj)
{
    this->_type = obj._type;
    return *this;
}
AMateria* Ice::clone() const
{
    AMateria *cure = new Ice();
    return cure;
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructot called" << std::endl;
}

