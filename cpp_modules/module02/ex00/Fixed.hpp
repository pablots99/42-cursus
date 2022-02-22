/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:15 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 23:39:25 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#if !defined(FIXED_HPP)
#define FIXED_HPP
#include <iostream>


class Fixed
{
private:
	int point_value;
	static const int fraction_bits = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const Fixed &f);
	Fixed & operator=(const Fixed &f);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	~Fixed();
};


#endif // FIXED_HPP
