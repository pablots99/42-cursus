/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:44:03 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 19:46:59 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"


int main() { 

    Animal* meta = new Animal();
    Animal* j = new Dog();
    Animal* c = new Cat();
    
    std::cout << meta->getType() << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << c->getType() << std::endl;
    j->makeSound();
    c->makeSound();
    meta->makeSound();
    delete meta;
    delete j;
    delete c;
    WrongAnimal *wmeta = new WrongAnimal();
    WrongAnimal* wc = new WrongCat();
    std::cout << wmeta->getType() << std::endl;
    std::cout << wc->getType() << std::endl;
    wc->makeSound();
    wmeta->makeSound();
    delete wmeta;
    delete wc;
    return (0);
}