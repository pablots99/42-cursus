/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:00:56 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 21:03:27 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name ){
	Zombie *z = new Zombie[N];
	std::string aux;

	for (int i = 0; i < N; i++) {
		aux = name;
		z[i].setName(aux.append(" ").append(std::to_string(i)));
	}
	return z;
}
