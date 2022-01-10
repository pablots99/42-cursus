/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:45 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/10 20:01:02 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	this->Hitpoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30; 
	std::cout << "FragTrap " << Name << " initialized"<< std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "High five me!!" << std::endl;
}

void FragTrap::attack(std::string const & target) {
	if(this->Hitpoints <= 0)
	{
		std::cout << "FragTrap " << Name;
		std::cout << " cannot attack " << target;
		return ;
	}
	std::cout << "FragTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}

FragTrap::~FragTrap() { 
	std::cout << "FragTrap " << Name << " destructor called" << std::endl;
}
