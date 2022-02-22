/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:02 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 15:35:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Cast.hpp"


//que hacer si es 1 char o int

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "error: need 1 argument" << std::endl;
        return (1);
    }
    Cast *cast =  new Cast(std::string(argv[1]));
    cast->printResult();
    return (0);
}