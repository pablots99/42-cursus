/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:36:06 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:53:50 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <fstream>



PresidentialPardonForm::PresidentialPardonForm(std::string target):
	Form("PresidentialPardonForm",25,5),
	_target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj):Form(obj)
{
	this->_target = obj._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm &obj)
{
	this->_target = obj._target;
	this->_signed = obj._signed;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
	this->is_executable(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;

}
