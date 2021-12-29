/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:40:30 by pablo             #+#    #+#             */
/*   Updated: 2021/12/28 14:34:58 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./srcs/Zombie.hpp"



int main() {
	std::cout << "more brinz started" << std::endl;
	int num  =10;
	Zombie *z = zombieHorde(num,"ZOMBIE!");
	for(int i = 0; i< num; i++)
	{
		std::cout << i << " ";
		z[i].announce();
	}
	delete [] z;

}
