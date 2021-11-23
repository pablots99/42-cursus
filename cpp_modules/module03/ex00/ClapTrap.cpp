/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:10:35 by pablo             #+#    #+#             */
/*   Updated: 2021/11/20 12:47:27 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	Name = "";
	Hitpoints = 10;
	Energy_points  = 10;
	Attack_damage  = 0;
	std::cout << "ClapTrap contructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string _Name){
	Name = _Name;
	Hitpoints = 10;
	Energy_points  = 10;
	Attack_damage  = 0;
	std::cout << "ClapTrap name contructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &c) {
	std::cout << "ClapTrap copy contructor called" << std::endl;
	*this = c;
}

ClapTrap & ClapTrap::operator=(ClapTrap &c) {
	this->Attack_damage = c.Attack_damage;
	this->Name = c.Name;
	this->Energy_points = c.Energy_points;
	this->Attack_damage = c.Attack_damage;
	return *this;
}

void ClapTrap::attack(std::string const &target){
	std::cout << "ClapTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount){
	Hitpoints -= amount;
	std::cout << Name << " takes "<< amount << " of damage. current: " << Hitpoints << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount){
	Hitpoints += amount;
	std::cout << Name << "rapairs "<< amount << " hitpoints! current: " << Hitpoints  << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;

}
