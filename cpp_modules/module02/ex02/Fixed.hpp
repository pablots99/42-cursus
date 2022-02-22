/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:15 by pablo             #+#    #+#             */
/*   Updated: 2021/11/17 19:35:08 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#if !defined(FIXED_HPP)
#define FIXED_HPP
#include <iostream>
#include <cmath>


class Fixed
{
private:

	int point_value;
	static const int  fraction_bits = 8;
public:
	Fixed( );
	Fixed(const int num);					//int constructor
	Fixed(const float num);					//float constructor
	Fixed(const Fixed &f);					//copy funciton
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	Fixed & operator = (const Fixed &f);		//asign operator
	//comparations
	bool  operator == (const Fixed &f);
	bool  operator != (const Fixed &f);
	bool  operator > (const Fixed &f);
	bool  operator >= (const Fixed &f);
	bool  operator < (const Fixed &f);
	bool  operator <= (const Fixed &f);
	float  operator + (const Fixed &f);
	float  operator - (const Fixed &f);
	float  operator * (const Fixed &f);
	float  operator / (const Fixed &f);
	Fixed  operator++(int);		//after
	Fixed  &operator++();		//pre
	Fixed  operator--(int);		//after
	Fixed  &operator--();		//pre
	static Fixed &min(Fixed &f1,Fixed &f2);
	static const Fixed &min(Fixed const &f1,Fixed const &f2);
	static Fixed &max(Fixed &f1,Fixed &f2);
	static const Fixed &max(Fixed const &f1,Fixed const &f2);
	~Fixed();
};
std::ostream &operator <<(std::ostream &os,Fixed const &f);


#endif // FIXED_HPP
