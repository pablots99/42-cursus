/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_constructor.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:35 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:51:55 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::vector<TYPE> v;
    LIBRARY::vector<int> v2;
    print_vec(v);
    print_vec(v2);
    v.push_back("a");
    print_vec(v);
    v2.push_back(1);
    print_vec(v2);
}
