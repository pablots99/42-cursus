/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:12:51 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 21:15:53 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HUMANB_CLASS_HPP
#define HUMANB_CLASS_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB {
public:
	HumanB(std::string name);
	void setWeapon(Weapon &weapon);
	void attack();
	~HumanB();
private:
	const std::string name;
	Weapon *weapon;
};


#endif
