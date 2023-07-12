/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:35 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/20 14:03:51 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::vector<TYPE> v;
    LIBRARY::vector<TYPE> v1(100,"1");
    LIBRARY::vector<TYPE> v2(100,"2");
    v.assign(0,"100");
    print_vec(v);
    v.assign(123,"asd");
    print_vec(v);
    v1.assign(v.begin(), v.end() - 10);
    print_vec(v1);
    v.assign(0,"asd");
    v2.assign(v1.end(),v1.end());
    print_vec(v);
    print_vec(v2);
}
