/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 18:04:59 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/14 02:57:41 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name)
{
    this->_name = name;
	for (size_t i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
    std::cout << "Character constructor called" << std::endl;
}


//cambiar esto
Character::Character(Character &obj)
{
    std::cout << "Charactec copy constructor called" << std::endl;
	this->_name = obj._name;
	for (size_t i = 0; i < 4; i++)
	{
		if(obj._inventory[i])
			this->_inventory[i] = obj._inventory[i]->clone();
		else
			this->_inventory[i]  = NULL;
	}
}


Character &Character::operator=(Character &obj)
{
	this->_name = obj._name;
	for (size_t i = 0; i < 4; i++)
	{
		if(this->_inventory[i])
			delete this->_inventory[i];
		if(obj._inventory[i])
			this->_inventory[i] = obj._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	return *this;
}

std::string const & Character::getName()const {
	return this->_name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	if(!m)
	{
		std::cout << "No Materia cannot equip" << std::endl;
		return ;
	}
	while (i < 4 && this->_inventory[i])
		i++;
	if(i == 4)
	{
		std::cout << this->_name << "inventory full cannot equip" << std::endl;
		return ;
	}
	else
     		this->_inventory[i] = m;
	std::cout << m->getType() << " Materia equiped!"<< std::endl;
}

void Character::unequip(int idx){

	if(idx < 0 || idx > 4)
	{
		std::cout << "Invalid inventory index"<< std::endl;
		return ;
	}
	if(!this->_inventory[idx])
	{
		std::cout << "Inventory slot is empty unable to unequip!"<< std::endl;
		return ;
	}
	std::cout << this->_inventory[idx]->getType() << " Unequiped"<< std::endl;
	this->_inventory[idx] = NULL;
}


AMateria *Character::getInventory() {
	return *this->_inventory;
}


void Character::use(int idx, ICharacter& target){


	if(idx < 0 || idx > 4)
	{
		std::cout << "Invalid inventory index"<< std::endl;
		return ;
	}
	if(!this->_inventory[idx])
	{
		std::cout << "Inventory slot is empty unable to use!"<< std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if(this->_inventory[i])
			delete this->_inventory[i];
	}
    std::cout << "Characcter destructor callled " << std::endl;
}
