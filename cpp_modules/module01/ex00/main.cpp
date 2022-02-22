/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:40:30 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 20:45:39 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/Zombie.hpp"



int main() {
	Zombie *z = newZombie("z1");
	randomChump("z2");
	Zombie *z3 = newZombie("z3");
	randomChump("z4");
	z3->announce();
	z->announce();
	delete z;
	delete z3;

}
