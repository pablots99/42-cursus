/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:42:23 by ptorres           #+#    #+#             */
/*   Updated: 2021/12/14 13:55:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FRAGTRAP_HPP)
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	void highFivesGuys(void);
	~FragTrap();
};

#endif 
