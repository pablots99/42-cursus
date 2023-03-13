/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_constructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:11:41 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:46:58 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::vector<TYPE> v;
    v.push_back("aaaa");
    print_vec(v);
    LIBRARY::vector<TYPE> v2(v);
    print_vec(v2);
    for (int i = 0; i < 100; i++)
    {
        v2.push_back("bbbbb");
    }
    LIBRARY::vector<TYPE> v3(v2);
    print_vec(v3);
    return (0);
}
