/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_operator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:07:35 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/09 19:51:58 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::vector<TYPE> v(100,"hello");
    LIBRARY::vector<TYPE> v2;
    v2 = v;
    print_vec(v);
    print_vec(v2);
}
