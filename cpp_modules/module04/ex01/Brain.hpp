/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:06:02 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/12 14:58:21 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


#ifndef BRAIN_HPP
#define BRAIN_HPP

class Brain
{
protected:
    std::string *_ideas;
public:
    Brain();
    Brain(Brain &brain);
    std::string *getIdeas();
    void setIdeas(std::string ideas);
    Brain &operator=(Brain &brain);
    ~Brain();
};

#endif