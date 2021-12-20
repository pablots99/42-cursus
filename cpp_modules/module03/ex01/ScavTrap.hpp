/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:53:54 by pablo             #+#    #+#             */
/*   Updated: 2021/12/14 13:57:40 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	void guardGate();
	ScavTrap(std::string name);
	void attack(std::string const & target);
	~ScavTrap();
};

