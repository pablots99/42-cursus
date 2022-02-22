/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:03:05 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 21:23:21 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
#define  WEAPON_CLASS_HPP
#include <iostream>

class Weapon {

private:
	std::string type;
public:
	Weapon(std::string type);
	const std::string &getType();
	void setType(std::string type);
	~Weapon();
};

#endif
