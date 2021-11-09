/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:31:34 by pablo             #+#    #+#             */
/*   Updated: 2021/11/02 18:10:58 by pablo            ###   ########.fr       */
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
	Zombie(void );

	void announce( void );
	void setName(std::string name);
	~Zombie();
};
Zombie* zombieHorde( int N, std::string name );

#endif
