/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:26 by pablo             #+#    #+#             */
/*   Updated: 2022/01/09 23:50:00 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(){
	this->point_value = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}


Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->point_value = num << this->fraction_bits;
}

Fixed::Fixed(const Fixed &f){
	std::cout << "Copy constructor called" << std::endl;
	this->point_value = f.getRawBits();
	return;
}

int  Fixed::getRawBits() const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->point_value;
}

void Fixed::setRawBits(int const raw ){
	this->point_value  = raw;
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Assignation operator Called" << std::endl;
	this->point_value = f.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor Called" << std::endl;
	return ;
}
