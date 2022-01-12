/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:50:27 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 18:13:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>
# include "ICharacter.hpp"


class AMateria
{
protected:
    std::string _type;
public:
    AMateria(std::string const & type);
    AMateria(AMateria &materia);
    ~AMateria();
    AMateria &operator=(AMateria &materia);
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0; //return instance of inherit class
    virtual void use(ICharacter& target);
};

#endif