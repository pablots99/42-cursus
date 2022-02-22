/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:27 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 21:04:46 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade):_name(name)
{
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat constructor called" << std::endl;

}
Bureaucrat::Bureaucrat(Bureaucrat &obj)
{
	*this = obj;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &obj)
{
	this->_grade = obj._grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
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

void Bureaucrat::signForm(Form   &form) const
{
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{

		std::cerr << "Bureocrat " <<  this->_name << " cannot sign form " <<
		form.getName() <<
		" because: " << e.what()  << std::endl;
		return ;
	}
}
void Bureaucrat::executeForm(Form const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Bureocrat " <<  this->_name << " cannot execute form " <<
		form.getName() <<
		" because: " << e.what()  << std::endl;
		return ;
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
