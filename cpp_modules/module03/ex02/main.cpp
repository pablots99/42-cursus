/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:36:43 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 20:00:50 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


int main() {

	FragTrap pablo("Pablo");
	ClapTrap juan("Juan");
	pablo.attack("Juan");
	juan.attack("Palo");
	pablo.takeDamage(100);
	pablo.beRepaired(32);
	pablo.highFivesGuys();

}
