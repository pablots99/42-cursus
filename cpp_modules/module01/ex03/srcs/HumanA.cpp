/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:13:50 by pablo             #+#    #+#             */
/*   Updated: 2021/12/28 18:02:28 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &_weapon) : name(name),weapon(_weapon){
	std::cout << this->name <<  " HumanA created" << std::endl;
}

void HumanA::attack(){
	std::cout << this->name << " attacks with " << this->weapon.getType() << std::endl;
}


HumanA::~HumanA(){
	std::cout <<  "HumanA destroyed" << std::endl;
}



