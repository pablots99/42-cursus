/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:14:31 by pablo             #+#    #+#             */
/*   Updated: 2021/12/29 13:24:35 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#if !defined(CLAPTRAP_HPP)
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
private:
	std::string Name;
	int Hitpoints;
	int Energy_points;
	int Attack_damage;
public:
	ClapTrap();
	ClapTrap(ClapTrap &c);
	ClapTrap & operator=(ClapTrap &c);
	ClapTrap(std::string Name);
	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};


#endif
