/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:43:45 by ptorres           #+#    #+#             */
/*   Updated: 2021/12/14 13:59:00 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fragtrap.hpp"


FragTrap::FragTrap(): ClapTrap()  {
	this->Attack_damage = 50;
	this->
	std::cout << "FragTrap constructor called"<< std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name,100,50,50) { 
	std::cout << "FragTrap constructor called"<< std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << "High five me!!" << std::endl;
}

FragTrap::~FragTrap() { 
	std::cout << "FragTrap destructor called" << std::endl;
}
