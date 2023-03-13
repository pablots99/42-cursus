/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:14:48 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:52:07 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"


int main() { 
    LIBRARY::vector<TYPE> lista;
    TYPE str;
    str = "hola";
    int n = 100000;
    for (int i = 0; i < n; ++i) 
    { 
        lista.push_back(str);
    }
    std::cout << lista[n -1];
    print_vec(lista);
}
