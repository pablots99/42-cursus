/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 20:24:55 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/20 14:25:02 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../utils.hpp"

int main()
{
    LIBRARY::vector<TYPE> v(100,"1");
    LIBRARY::vector<TYPE> v1;

    std::cout << "default_insert " << std::endl;
    std::cout << * v.insert(v.begin() + 10, "jajajjaj") << std::endl;
    print_vec(v);
    std::cout << * v.insert(v.begin() + 10, "jojojojo") << std::endl;
    print_vec(v);
    std::cout << * v.insert(v.begin() + 10, "jejejeje") << std::endl;
    print_vec(v);

    std::cout << "range_insert:" << std::endl;
    v1.insert(v1.begin(),v.begin(),v.end());
    print_vec(v1);
}
