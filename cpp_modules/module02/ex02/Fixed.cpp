/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:50:26 by pablo             #+#    #+#             */
/*   Updated: 2022/01/10 00:16:37 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed(){
	this->point_value = 0;
	return;
}

Fixed::Fixed(const Fixed &f){
	this->point_value = f.getRawBits();
	return;
}

Fixed::Fixed(const int num) {
	this->point_value = num << this->fraction_bits;
}

Fixed::Fixed(const float num) {
	this->point_value = std::roundf((num) * (1 << this->fraction_bits));
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
	this->point_value = f.getRawBits();
	return *this;
}




bool Fixed::operator == (const Fixed &f) {
	return this->getRawBits() == f.getRawBits();
}

bool Fixed::operator != (const Fixed &f) {
	return this->getRawBits() != f.getRawBits();
}

bool Fixed::operator > (const Fixed &f) {
	return this->getRawBits() > f.getRawBits();
}

bool Fixed::operator >= (const Fixed &f) {
	return this->getRawBits() >= f.getRawBits();
}


bool Fixed::operator <= (const Fixed &f) {
	return this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator < (const Fixed &f) {
	return this->getRawBits() < f.getRawBits();
}




float Fixed::operator + (const Fixed &f) {

	return this->toFloat() + f.toFloat();
}

float Fixed::operator - (const Fixed &f) {
	return this->toFloat() - f.toFloat();
}
float Fixed::operator * (const Fixed &f) {
	return this->toFloat() * f.toFloat();
}

float Fixed::operator / (const Fixed &f) {
	return this->toFloat() / f.toFloat();
}

Fixed Fixed::operator++(int) {
	Fixed res = Fixed(*this);
	this->point_value++;
	return res;
}

Fixed& Fixed::operator++() {
	this->point_value+=1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed res = Fixed(*this);
	this->point_value--;
	return res;
}

Fixed& Fixed::operator--() {
	this->point_value-=1;
	return *this;
}
Fixed & Fixed::min(Fixed &f1,Fixed &f2){
	return (f1.point_value > f2.point_value)?f2:f1;
}
const Fixed &Fixed::min(Fixed const &f1,Fixed const &f2){
	return (f1.point_value > f2.point_value)?f2:f1;
}

Fixed & Fixed::max(Fixed &f1,Fixed &f2){
	return (f1.point_value < f2.point_value)?f2:f1;
}

const Fixed &Fixed::max(Fixed const &f1,Fixed const &f2){
	return (f1.point_value < f2.point_value)?f2:f1;
}

std::ostream &operator<<(std::ostream &os,Fixed const &f){
	os << f.toFloat();
	return os;
}


Fixed::~Fixed(){
	return ;
}
