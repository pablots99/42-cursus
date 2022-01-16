/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:56:26 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 19:27:32 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(std::string name,  int sign_req, int exec_req):
	_name(name),
	_sign_req(sign_req),
	_exec_req(exec_req),
	_signed(false)
{
	if(_sign_req < 1 || _exec_req < 1)
		throw Form::GradeTooHighException();
	if(_sign_req > 150 || _exec_req > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(Form &obj):
_name(obj._name),
_sign_req(obj._sign_req),
_exec_req(obj._exec_req),
_signed(obj._signed)
{

}


Form &Form::operator=(Form &obj)
{
	this->_signed = obj._signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


void Form::beSigned(Bureaucrat &b)
{
	if(this->_signed)
	{
		throw FormSignedException();
		return ;
	}
	if(b.getGrade() <= this->_sign_req)
	{
		this->_signed = true;
		std::cout << "Bureaucrat " << b.getName()  << " signs " << this->_name << std::endl;
		return ;
	}
	throw GradeTooLowException();
}


int Form::getSign_req() const
{
	return this->_sign_req;
}

int Form::getExec_req() const
{
	return this->_exec_req;
}

bool Form::getSigned()  const
{
	return this->_signed;
}
std::string Form::getName() const {
	return this->_name;
}


std::ostream &operator<<(std::ostream &os, Form const &b)
{
	os << b.getName() <<
	", signed status:  " << b.getSigned() <<
	", sign requested grade: " << b.getSign_req() <<
	", exec requested grade: " << b.getExec_req();
	return os;
}
