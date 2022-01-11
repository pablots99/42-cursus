/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:45 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 16:37:54 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30; 
	_Hitpoints  	=    Hitpoints ;
	_Energy_points  =	 Energy_points;
	_Attack_damage  = 	 Attack_damage;
	std::cout << "FragTrap " << Name << " initialized"<<
		" HP:" << this->Hitpoints <<
		" EP:" << this->Energy_points << 
		" AD:" << this->Attack_damage <<  std::endl;
}

FragTrap::FragTrap(FragTrap &f) : ClapTrap(f) {
	std::cout << "FragTrap copy contructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "High five me!!" << std::endl;
}

void FragTrap::attack(std::string const &target){
	if(this->Hitpoints <= 0)
	{
		std::cout << "FragTrap " << Name;
		std::cout << " cannot attack " << target;
		std::cout << ", is offline"    << std::endl;
		return ;
	}
	if(Energy_points - Attack_damage < 0)
	{
		std::cout << "FragTrap " << Name;
		std::cout << " cannot attack " << target;
		std::cout << ", not enought Energy points. Ep: " << Energy_points << std::endl;
		return ;
	}
	Energy_points -= Attack_damage;
	std::cout << "FragTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}

FragTrap::~FragTrap() { 
	std::cout << "FragTrap " << Name << " destructor called" << std::endl;
}
