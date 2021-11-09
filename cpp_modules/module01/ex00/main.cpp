/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:40:30 by pablo             #+#    #+#             */
/*   Updated: 2021/11/02 17:59:55 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/Zombie.hpp"



int main() {
	std::cout << "brinz started" << std::endl;
	Zombie *z = newZombie("z1");
	randomChump("z2");
	Zombie *z3 = newZombie("z3");
	randomChump("z4");
	delete z;
	delete z3;

}
