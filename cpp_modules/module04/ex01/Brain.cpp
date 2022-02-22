/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:05:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 15:43:03 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    this->_ideas = new std::string[100];
    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = "empty idea";
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    this->_ideas = new std::string[100];
    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = brain._ideas[i];
}


std::string *Brain::getIdeas()
{
    return this->_ideas;
}

void Brain::setIdeas(std::string ideas)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->_ideas[i] = ideas + " " + std::to_string(i);
    }
}

Brain &Brain::operator=(Brain &brain){

    for (size_t i = 0; i < 100; i++)
        this->_ideas[i] = brain._ideas[i];
    return *this;
}

Brain::~Brain(){ 
    delete[] this->_ideas;
    std::cout << "Brain destructor called" << std::endl;
}