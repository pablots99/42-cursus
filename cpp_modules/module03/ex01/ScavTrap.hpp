/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:53:54 by pablo             #+#    #+#             */
/*   Updated: 2022/01/11 14:59:53 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &s);
	ScavTrap & operator=(ScavTrap &s);
	~ScavTrap();
	
	void guardGate();
	void attack(std::string const & target);
};

