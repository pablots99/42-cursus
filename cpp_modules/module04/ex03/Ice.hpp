/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 22:08:54 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 00:07:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
private:
public:
	Ice();
    Ice(Ice & obj);
    Ice &operator=(Ice &obj);
    AMateria* clone() const;
    void use(ICharacter& target);
    ~Ice();
};



#endif
