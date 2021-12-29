/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:31:34 by pablo             #+#    #+#             */
/*   Updated: 2021/12/28 14:20:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;
public:
	Zombie(std::string name);
	void announce( void );
	~Zombie();
};
Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif
