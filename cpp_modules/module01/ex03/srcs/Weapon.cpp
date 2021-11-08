/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:04:28 by pablo             #+#    #+#             */
/*   Updated: 2021/11/08 18:27:23 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"



Weapon::Weapon(std::string type) {
	this->type = type;
}

void Weapon::setType(std::string type){
	this->type = type;
}
std::string Weapon::getType(){
	return this->type;
}
Weapon::~Weapon(){

}
