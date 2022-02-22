/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:19:23 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/13 23:53:12 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure :public AMateria
{
private:
public:
    Cure();
    Cure(Cure & obj);
    Cure &operator=(Cure &obj);
    AMateria* clone() const;
    void use(ICharacter& target);
    ~Cure();
};


#endif
