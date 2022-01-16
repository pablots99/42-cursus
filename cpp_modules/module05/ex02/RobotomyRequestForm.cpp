/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:36:06 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:46:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <fstream>

int RobotomyRequestForm::_times_executed = 0;

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	Form("RobotomyRequestForm",72,45),
	_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &obj):Form(obj)
{
	this->_target = obj._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm &obj)
{
	this->_target = obj._target;
	this->_signed = obj._signed;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute( const Bureaucrat &executor ) const
{
	this->is_executable(executor);
	std::cout << "*LOUD DRILLING NOISES.....*" << std::endl;
	this->_times_executed++;
	if(this->_times_executed % 2)
		std::cout << this->_target << " has been lobotomized successfully" << std::endl;
	else
		std::cout << this->_target << " the lobotomization failed this target is dangerous!" << std::endl;
}
