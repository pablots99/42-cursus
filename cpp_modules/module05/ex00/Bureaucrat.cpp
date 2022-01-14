/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:27 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 03:49:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade)
{
	this->_name = name;
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;

}
Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &obj)
{
	if(this->_name.length())
		this->_name = obj._name;
	this->_grade = obj._grade;
	return *this;
}
Bureaucrat::~Bureaucrat()
{

}
std::string Bureaucrat::getName()
{
	return this->_name;
}
int Bureaucrat::getGrade()
{
	return this->_grade;
}

void Bureaucrat::incremetGrade()
{
	if(this->_grade -1 < 1 )
		throw Bureaucrat::GradeTooHighException();
	this->_grade -=1;

}
void Bureaucrat::decrementGrade()
{
	if(this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
		this->_grade +=1;
}


std::ostream &operator<<(std::ostream os, Bureaucrat const b)
{
	os << b->_name << ", bureaucrat grade " << b->_grade;
	return os;
}
