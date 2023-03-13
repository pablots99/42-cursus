/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_constructor.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:35 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:52:01 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::vector<TYPE> v(12,"hello");
    print_vec(v);
    LIBRARY::vector<int> v2(120,0);
    print_vec(v2);
    LIBRARY::vector<TYPE> v3(120);
    print_vec(v3);
}
