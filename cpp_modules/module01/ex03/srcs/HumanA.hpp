/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:12:51 by pablo             #+#    #+#             */
/*   Updated: 2021/11/08 18:34:22 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
#define HUMANA_CLASS_HPP

#include "Weapon.hpp"
#include <iostream>


class HumanA {
public:
	HumanA(std::string name,Weapon &_weapon);
	void attack();
	~HumanA();
private:
	HumanA();
	std::string name;
	Weapon &weapon;
};


#endif
