/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:53:49 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 19:38:09 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void ScavTrap::guardGate() {
	std::cout << "ScavTrap "<< Name << " have enterred in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->Energy_points = 50;
	this->Attack_damage = 20;
	this->Hitpoints = 100;
	std::cout << "ScavTrap " << this->Name <<  " initialized"<<
	" HP:" << this->Hitpoints <<
	" EP:" << this->Energy_points << 
	" AD:" << this->Attack_damage << std::endl;
}


void ScavTrap::attack(std::string const & target) {
	if(this->Hitpoints <= 0)
	{
		std::cout << "ScavTrap " << Name;
		std::cout << " cannot attack " << target;
		return ;
	}
	std::cout << "ScavTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " destructor called" << std::endl;
}
