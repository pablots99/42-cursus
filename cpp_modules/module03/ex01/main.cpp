/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:36:43 by pablo             #+#    #+#             */
/*   Updated: 2022/01/11 15:02:26 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main() {

	ScavTrap pablo("Pablo");
	ClapTrap juan("Juan");
	pablo.attack("Juan");
	juan.attack("Pablo");
	pablo.takeDamage(100);
	pablo.beRepaired(32);
	pablo.attack("Juan");
	pablo.attack("Juan");
	pablo.attack("Juan");
	pablo.attack("Juan");

	pablo.guardGate();

}
