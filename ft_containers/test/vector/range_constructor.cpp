/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_constructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:20:27 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:04:46 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{ 
    LIBRARY::vector<TYPE> v;
    for (size_t i = 0; i < 100; i++)
        v.push_back("number: " + std::to_string(i));
    print_vec(v);
    LIBRARY::vector<TYPE> v2(v.begin(),v.end());
    print_vec(v2);
    LIBRARY::vector<TYPE> v3;
    v3.push_back("1");
    v3.push_back("2");
    print_vec(v3);
    LIBRARY::vector<TYPE> v4(v3.begin(),v3.end());
    print_vec(v4);
    return 0;
}
