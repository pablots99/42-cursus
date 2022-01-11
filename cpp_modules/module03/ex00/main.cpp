/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:36:43 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 19:20:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main() {

	ClapTrap p("Pablo");
	ClapTrap p1("Pablo1");
	ClapTrap cp(p);
	p.attack("juan");
	p = p1;
	p.attack("alberto");
	p.beRepaired(10);
	p.takeDamage(10);
	p.takeDamage(10);
	p.takeDamage(10);
}
