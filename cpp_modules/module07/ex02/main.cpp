/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:24:04 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/19 16:11:20 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

#define MAX_VAL 20
int main(int, char**)
{
    std::cout << "empty Array" << std::endl << "-----------------" << std::endl;
    Array<int> a;
    std::cout << "int type" << std::endl << "-------------------" << std::endl; 
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 20;
        numbers[i] = value;
        mirror[i] = value;
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << i << ": " << numbers[i] << std::endl;
    }
    std::cout << "Last: " << numbers[MAX_VAL - 1] << std::endl;
    std::cout << "complex type" << "-------------------" << std::endl;
    Array<std::string> s(10);
    Array<std::string> s2(10);
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = std::to_string(i) + " hola";
    }
    for (int i = 0; i < s.size(); i++)
    {
        std::cout << s[i] << std::endl;
    }
    std::cout << s[9] << std::endl;
    s2 = s;
    std::cout << "change last element of array" << std::endl;
    s[9] = "aaaaaaaaa";
    std::cout << s[9] << std::endl;
    std::cout << "Deep copy " << std::endl;
    for (int i = 0; i < s2.size(); i++)
    {
        std::cout << s2[i] << std::endl;
    }
    delete [] mirror;
    return 0;
}