/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:13:50 by pablo             #+#    #+#             */
/*   Updated: 2021/11/08 18:35:56 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &_weapon) : weapon(_weapon){
	this->name = name;
}

void HumanA::attack(){
	std::cout << this->name << " attacks with his " << this->weapon.getType() << std::endl;
}


HumanA::~HumanA(){

}



