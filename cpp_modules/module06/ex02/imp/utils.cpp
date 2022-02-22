/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:12:38 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 18:34:24 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../def/Base.hpp"
#include "../def/A.hpp"
#include "../def/B.hpp"
#include "../def/C.hpp"
#include <cstdlib>
#include <ctime>
Base * generate(void)
{
    srand(time(NULL));
    int random = (rand() % 3) + 1;
    switch (random)
    {
    case 1:
        return new A();break;
    case 2:
        return new B();break;
    case 3:
        return new C();break;
    }
    return new A();
}

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;;
    if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;;
   
}


void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;;
        (void) dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;;
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;;
    }
    catch(const std::exception& e)
    {
    }
}