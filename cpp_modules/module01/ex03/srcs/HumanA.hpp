/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:12:51 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 21:15:13 by pablo            ###   ########.fr       */
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
	const std::string name;
	Weapon &weapon;
};


#endif
