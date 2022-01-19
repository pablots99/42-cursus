/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:16:34 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/19 17:23:31 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "eayfind.hpp"

#include <iostream>
#include <list>
#include <vector>

int main()
{
    std::list<int> l;
    std::vector<int> v;

    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    std::list<int>::iterator it;

    for (it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
    



}