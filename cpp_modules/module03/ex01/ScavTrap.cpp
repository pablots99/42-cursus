/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:53:49 by pablo             #+#    #+#             */
/*   Updated: 2021/11/20 14:43:26 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


void ScavTrap::guardGate() {
	std::cout << " ScavTrap have enterred in Gate keeper mode." << std::endl;
}

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap contructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target) {
	std::cout << "ScavTrap " << Name;
	std::cout << " attack " << target;
	std::cout << " causing " << Attack_damage << " points of damage!" << std::endl;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name,100,50,20){
	std::cout << "ScavTrap name contructor called" << std::endl;
}
