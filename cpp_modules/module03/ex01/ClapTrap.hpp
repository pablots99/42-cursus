/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:14:31 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 19:27:08 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if !defined(CLAPTRAP_HPP)
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	int Hitpoints;
	int Energy_points;
	std::string Name;
	int Attack_damage;
public:
	ClapTrap(std::string Name);
	ClapTrap(ClapTrap &c);
	ClapTrap & operator=(ClapTrap &c);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};


#endif // MACRO
