/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:58:13 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/14 00:29:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"


class Character:public ICharacter
{
private:
    std::string _name;
    AMateria *_inventory[4];
public:
    Character(std::string name);
    Character(Character &obj);
    Character &operator=(Character &obj);
	std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
 	void use(int idx, ICharacter& target);
	AMateria *getInventory();
    ~Character();
};

#endif
