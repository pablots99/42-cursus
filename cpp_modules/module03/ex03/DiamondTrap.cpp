/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:15:14 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 16:15:09 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string _Name):
    ClapTrap(_Name + "_clap_name"),
    ScavTrap(_Name+ "_clap_name"),
    FragTrap(_Name + "_clap_name")
{   
    this->Name = _Name;
    this->Hitpoints = FragTrap::_Hitpoints;
    this->Energy_points = ScavTrap::_Energy_points;
    this->Attack_damage = FragTrap::_Attack_damage;
    std::cout << "DiamondTrap " << this->Name << " Initialized" << 
		" HP:" << this->Hitpoints <<
		" EP:" << this->Energy_points << 
		" AD:" << this->Attack_damage << 
	std::endl;
}

void DiamondTrap::attack(std::string const & target ){
    FragTrap::attack(target);
}
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << Name << " destructor called" << std::endl;    
}
void DiamondTrap::whoAmI(){
    std::cout << "My name is " << this->Name
    << " and my ClapTrap name is " << ClapTrap::Name 
    << std::endl;
}
