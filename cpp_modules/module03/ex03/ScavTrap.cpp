/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:53:49 by pablo             #+#    #+#             */
/*   Updated: 2022/01/11 16:14:26 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

void ScavTrap::guardGate() {
	std::cout << "ScavTrap "<< Name << " have enterred in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->Energy_points = 50;
	this->Attack_damage = 20;
	this->Hitpoints = 100;
	_Hitpoints  	=    Hitpoints ;
	_Energy_points  =	 Energy_points;
	_Attack_damage  = 	 Attack_damage;
	std::cout << "ScavTrap " << this->Name <<  " initialized"<<
	" HP:" << this->Hitpoints <<
	" EP:" << this->Energy_points << 
	" AD:" << this->Attack_damage << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &s) :  ClapTrap(s){
	std::cout << "ScavTrap copy contructor called" << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap &s) {
	this->Attack_damage = s.Attack_damage;
	this->Name = s.Name;
	this->Energy_points = s.Energy_points;
	this->Attack_damage = s.Attack_damage;
	return *this;
}

void ScavTrap::attack(std::string const &target){
	if(this->Hitpoints <= 0)
	{
		std::cout << "ScavTrap " << Name;
		std::cout << " cannot attack " << target;
		std::cout << ", is offline"    << std::endl;
		return ;
	}
	if(Energy_points - Attack_damage < 0)
	{
		std::cout << "ScavTrap " << Name;
		std::cout << " cannot attack " << target;
		std::cout << ", not enough Energy points. Ep: " << Energy_points << std::endl;
		return ;
	}
	Energy_points -= Attack_damage;
	std::cout << "ScavTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " destructor called" << std::endl;
}
