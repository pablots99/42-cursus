/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 12:36:43 by pablo             #+#    #+#             */
/*   Updated: 2022/01/11 14:27:26 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


int main() {	
	ClapTrap pablo("Pablo");
	ClapTrap alberto("Alberto");

	pablo.attack("Alberto");
	alberto.attack("Pablo");
	pablo.takeDamage(10);
	pablo.takeDamage(10);
	pablo.takeDamage(10);
	pablo.attack("Alberto");
}
