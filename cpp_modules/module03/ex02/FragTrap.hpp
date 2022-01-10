/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:42:23 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/10 19:59:45 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
public:
	FragTrap(std::string name);
	void attack(std::string const & target);
	void highFivesGuys(void);
	~FragTrap();
};

