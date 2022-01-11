/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:05:54 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/11 21:14:30 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &brain)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = brain;
}

//fix Brain operator
// Brain &Brain::operator=(Brain &brain){

//     this->_ideas = brain._ideas;
//     return *this;
// }

Brain::~Brain(){ 
    std::cout << "Braain destructor called" << std::endl;
}