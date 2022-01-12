/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:19:23 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 17:52:48 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure : AMateria
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