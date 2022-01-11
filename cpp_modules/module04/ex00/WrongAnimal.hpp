/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:57:59 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 19:44:13 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(WrongAnimal &animal);
    WrongAnimal &operator=(WrongAnimal &animal);
    virtual ~WrongAnimal();
    virtual void makeSound();
    std::string getType();
};