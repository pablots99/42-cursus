/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:33:01 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/18 17:58:30 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "data.hpp"

uintptr_t serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return raw;
}
Data* deserialize(uintptr_t raw)
{
    Data * ptr = reinterpret_cast<Data *>(raw);
    return ptr;
}

int main() 
{
    Data data;
    data.data = 100;
    uintptr_t raw = serialize(&data);
    Data *ptr = deserialize(raw);

    std::cout << "Raw: " << raw << std::endl;
    std::cout <<"data: " << ptr->data << std::endl;
}