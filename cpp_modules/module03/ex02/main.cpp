/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:36:43 by pablo             #+#    #+#             */
/*   Updated: 2021/12/13 16:29:20 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


int main() {

	ScavTrap p("Pablo");
	ScavTrap p1("Pablo1");
	ScavTrap j("Pablo");
	ScavTrap cp(p);
	p.attack("juan");
	p = p1;
	p.attack("alberto");
	p.beRepaired(10);
	p.takeDamage(10);
	p.guardGate();
}
