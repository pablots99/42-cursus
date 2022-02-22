/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:27 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/13 22:07:33 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria;

# include "ICharacter.hpp"


class AMateria
{
protected:
    std::string _type;
public:
    AMateria(std::string const & type);
    AMateria(AMateria &materia);
    virtual ~AMateria();
    AMateria &operator=(AMateria &materia);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0; //return instance of inherit class
    virtual void use(ICharacter& target);
};

#endif
