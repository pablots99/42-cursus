/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:39:38 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 21:16:36 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain *_brain;
public:
    Cat();
    Cat(Cat &cat);
    Cat &operator=(Cat &animal);
    void makeSound();
    ~Cat();
};

#endif
