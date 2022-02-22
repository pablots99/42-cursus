/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:42:23 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 16:18:10 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
class FragTrap : public virtual ClapTrap
{
public:
	FragTrap(std::string name);
	FragTrap(FragTrap &f);
	void attack(std::string const & target);
	void highFivesGuys(void);
	~FragTrap();
protected:
	int _Hitpoints;
	int _Energy_points;
	int _Attack_damage;
};

