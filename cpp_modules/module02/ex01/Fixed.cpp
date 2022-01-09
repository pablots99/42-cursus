/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:26 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 00:08:30 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(){
	this->point_value = 0;
	std::cout << "Default constructor called" << std::endl;
	return;
}

Fixed::Fixed(const Fixed &f){
	std::cout << "Copy constructor called" << std::endl;
	this->point_value = f.getRawBits();
	return;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	this->point_value = num << this->fraction_bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	this->point_value = std::roundf((num) * (1 <<  this->fraction_bits));
}



int Fixed::toInt() const{
	return this->point_value >> this->fraction_bits;
}


float Fixed::toFloat() const{
	return ((float)this->point_value / (float)(1 << this->fraction_bits));
}


int  Fixed::getRawBits() const{
	return this->point_value;
}

void Fixed::setRawBits(int const raw ){
	this->point_value  = raw;
}

Fixed &Fixed::operator=(const Fixed &f) {
	std::cout << "Asign operator Called" << std::endl;
	this->point_value = f.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &os,Fixed const &f){
	os << f.toFloat();
	return os;
}


Fixed::~Fixed(){
	std::cout << "Destructor Called" << std::endl;
	return ;
}
