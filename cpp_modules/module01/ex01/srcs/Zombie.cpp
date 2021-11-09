/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:31:31 by pablo             #+#    #+#             */
/*   Updated: 2021/11/02 18:11:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
	this->announce();
}
Zombie::Zombie(){
}


void Zombie::announce(){
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name) {
	this->_name = name;
}

Zombie::~Zombie(){
	std::cout << this->_name << " destroyed" << std::endl;
}

