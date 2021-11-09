/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:00:56 by pablo             #+#    #+#             */
/*   Updated: 2021/11/02 18:14:42 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name ){
	Zombie *z = new Zombie[N];

	for (int i = 0; i < N; i++) { 
		z[i].setName(name);
	}
	return z;
}
