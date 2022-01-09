/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:31:31 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 20:59:20 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
	this->_name = name;
	std::cout << this->_name << " Created" << std::endl;
}


Zombie::Zombie(){
	std::cout << "Zombie Created" << std::endl;
}

std::string Zombie::getName() {
	return this->_name;
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

