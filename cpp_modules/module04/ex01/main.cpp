/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:06:18 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 15:42:42 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define SIZE  10

int main()
{
    Animal *arr[SIZE];
    for (size_t i = 0; i < SIZE / 2; i++)
    {
        std::cout << i << " --------------------" << std::endl;
        arr[i] = new Dog();
        std::cout << (SIZE - 1) - i << " --------------------" << std::endl;
        arr[(SIZE - 1) - i] = new Cat();
    }
    for (size_t i = 0;  i < SIZE; i++)
        std::cout << i << ": " <<    arr[i]->getType() << std::endl;

        
    std::cout << "Deep copys!!! " <<std::endl << "----------------------" << std::endl;
    std::cout << "Dog ->>>>>>>>>>>>>>>>>" << std::endl;
    Dog *d = dynamic_cast<Dog*>(arr[0]);
    d->brain->setIdeas("dog ideas");
    std::cout << "dog idea 0: " << d->brain->getIdeas()[0] << std::endl;    
    Dog *cpd = new Dog(*dynamic_cast<Dog*>(arr[0]));
    cpd->brain->setIdeas("new dog ideas");
    std::cout << "dog idea 0: " << d->brain->getIdeas()[0] << std::endl;    
    std::cout << "copy ddog idea 0: " << cpd->brain->getIdeas()[0] << std::endl;
    
    std::cout << "Cat ->>>>>>>>>>>>>>>>>" << std::endl;
    Cat *c = dynamic_cast<Cat*>(arr[5]);
    c->brain->setIdeas("cat ideas");
    std::cout << "cat idea 0: " << c->brain->getIdeas()[0] << std::endl;    
    Cat *cpc = new Cat(*dynamic_cast<Cat*>(arr[5]));
    cpc->brain->setIdeas("new cat ideas");
    std::cout << "cat idea 0: " << c->brain->getIdeas()[0] << std::endl;    
    std::cout << "copy cat idea 0: " << cpc->brain->getIdeas()[0] << std::endl;
    for (size_t i = 0;  i < SIZE; i++)
    {
        std::cout << i <<" -------------------" << std::endl;
        delete arr[i];
    }
    return (0);
}