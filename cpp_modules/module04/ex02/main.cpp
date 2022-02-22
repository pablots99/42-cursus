/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:50:23 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 16:36:00 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"


int main() { 
    Animal *d = new Dog();
    Animal *c = new Cat();;
    c->makeSound();
    d->makeSound();
    delete c;
    delete d;
    return 0;
}