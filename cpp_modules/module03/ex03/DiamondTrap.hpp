/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:33:02 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 16:18:15 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public  ScavTrap, public FragTrap
{
private:
    std::string  Name;
public:
    DiamondTrap(std::string Name);
    void attack(std::string const & target );
    void whoAmI();
    ~DiamondTrap();
};
