/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contructors.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:02:12 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/20 20:11:20 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::map<int, int> m1;
    m1.insert(LIBRARY::pair<int, int>(1, 1));
    m1.insert(LIBRARY::pair<int, int>(2, 4));

    print_map(m1);

    LIBRARY::map<int, int> m2(m1);
    m2.insert(LIBRARY::pair<int, int>(3, 9));
    
    print_map(m2);

    return(0);
}
