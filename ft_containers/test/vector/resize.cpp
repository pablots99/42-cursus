/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:31:52 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/20 18:12:24 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"


int main()
{

    LIBRARY::vector<TYPE> v(100,"1");
    print_vec(v);
    v.resize(10);
    print_vec(v);
    v.resize(0);

    LIBRARY::vector<TYPE> v2;
    v2.push_back("1");
    v2.push_back("2");
    v2.push_back("3");
    print_vec(v2);
    v2.resize(2);
    print_vec(v2);
    v2.resize(5);
    print_vec(v2);

    LIBRARY::vector<int>i (5,1);
    print_vec(i);
    i.resize(3,2);
	std::cout << "i.resize(3,2)" << std::endl;
    print_vec(i);
    i.resize(12,2);
	std::cout << "i.resize(12,2)" << std::endl;
    print_vec(i);
	std::cout << std::endl;

}
