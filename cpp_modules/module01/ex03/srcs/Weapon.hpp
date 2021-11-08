/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:03:05 by pablo             #+#    #+#             */
/*   Updated: 2021/11/08 18:12:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
#define  WEAPON_CLASS_HPP
#include <iostream>

class Weapon {

public:
	Weapon(std::string type);
	std::string getType();
	void setType(std::string type);
	~Weapon();
private:
	std::string type;
};

#endif
