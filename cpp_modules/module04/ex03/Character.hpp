/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:58:13 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 18:08:10 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character: ICharacter
{
private:
    std::string name;
    AMateria *materia[4];
public:
    Character(std::string name);
    Character(Character *obj);
    Character &operator=(Character *obj);
    ~Character();
};



#endif

