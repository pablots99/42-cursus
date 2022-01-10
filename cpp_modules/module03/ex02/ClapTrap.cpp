/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:10:35 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 19:58:12 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _Name): 
	Name(_Name),
	Hitpoints(10),
	Energy_points(10),
	Attack_damage(0) {
	std::cout << "ClapTrap " << this->Name << " Initialized" << 
		" HP:" << this->Hitpoints <<
		" EP:" << this->Energy_points << 
		" AD:" << this->Attack_damage << 
	std::endl;
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
	if(this->Hitpoints <= 0)
	{
		std::cout << "ClapTrap " << Name;
		std::cout << " cannot attack " << target;
		return ;
	}
	std::cout << "ClapTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(Hitpoints)
		std::cout << Name << " takes "<< amount << " of damage. ";
	Hitpoints -= amount;
	if(Hitpoints <= 0)
	{
		Hitpoints = 0;
		std::cout << Name << " Cannot take more damage ";
	}	
	std::cout<< " current HP: " << Hitpoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	Hitpoints += amount;
	std::cout << Name << " rapairs "<< amount << " hitpoints! Current HP: " << Hitpoints  << std::endl;
}
ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << Name << " destructor called" << std::endl;

}
