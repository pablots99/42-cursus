/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_size.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:55:06 by ptorres           #+#    #+#             */
/*   Updated: 2023/03/20 16:05:23 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.hpp"

int main()
{
    LIBRARY::vector<int> s1;
    std::cout << "max_size: " << s1.max_size() << std::endl;
    s1.push_back(1);
    s1.push_back(2);
    s1.push_back(212121);
    print_vec(s1);
    s1.clear();
    print_vec(s1);
    std::cout << "max_size: " << s1.max_size() << std::endl;
    LIBRARY::vector<char> v02;
    LIBRARY::vector<char16_t> v03;
    LIBRARY::vector<char32_t> v04;
    LIBRARY::vector<wchar_t> v05;
    LIBRARY::vector<signed char> v06;
    LIBRARY::vector<short int> v07;
    LIBRARY::vector<int> v08;
    LIBRARY::vector<long int> v09;
    LIBRARY::vector<unsigned char> v10;
    LIBRARY::vector<unsigned short int> v11;
    LIBRARY::vector<unsigned int> v12;
    LIBRARY::vector<unsigned long int> v13;
    std::cout << "char:" << std::endl;
    print_vec(v02);
    std::cout << "char16_t:" << std::endl;
    print_vec(v03);
    std::cout << "char32_t:" << std::endl;
    print_vec(v04);
    std::cout << "wchar_t:" << std::endl;
    print_vec(v05);
    std::cout << "signed char:" << std::endl;
    print_vec(v06);
    std::cout << "short int:" << std::endl;
    print_vec(v07);
    std::cout << "int:" << std::endl;
    print_vec(v08);
    std::cout << "ling int:" << std::endl;
    print_vec(v09);
    std::cout << "unsigned char:" << std::endl;
    print_vec(v10);
    std::cout << "unsigned short int:" << std::endl;
    print_vec(v11);
    std::cout << "unsigned int:" << std::endl;
    print_vec(v12);
    std::cout << "unsigned long int:" << std::endl;
    print_vec(v13);

    return (0);
}
