/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:26:47 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 21:24:12 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "srcs/Weapon.hpp"
#include "srcs/HumanA.hpp"
#include "srcs/HumanB.hpp"

int main()
{
		Weapon club("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
		Weapon club2("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club2);
		jim.attack();
		club2.setType("some other type of club");
		jim.attack();
}
