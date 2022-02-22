/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:13 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 00:25:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
//http://www.sunshine2k.de/articles/coding/fp/sunfp.html
int main()
{

	// Fixed a(1.1f);
	// Fixed b(2.2f);
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	std::cout <<  Fixed::min(a, b) << std::endl;
	std::cout << "----------------------" << std::endl;
	a = 1.1f;
	Fixed c(1.1f);
	std::cout << (a == c) << std::endl;
	std::cout << (a != c) << std::endl;
	std::cout << (a <= c) << std::endl;
	std::cout << (a >= c) << std::endl;
	c = -1;
	std::cout << (a < c) << std::endl;
	std::cout << (a > c) << std::endl;
	c = 2;
	std::cout << a / c << std::endl;
	std::cout << a * c << std::endl;
	std::cout << a - c << std::endl;
	std::cout << a + c << std::endl;
	return (0);
}
