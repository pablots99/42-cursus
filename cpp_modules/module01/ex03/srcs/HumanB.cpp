/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:13:50 by pablo             #+#    #+#             */
/*   Updated: 2021/11/08 18:33:00 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name){
	this->name = name;
}

void HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

void HumanB::attack(){
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

HumanB::~HumanB() {

}
