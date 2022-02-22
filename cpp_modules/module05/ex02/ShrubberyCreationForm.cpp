/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 19:36:06 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:17:42 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>



ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	Form("ShrubberyCreationForm",145,137),
	_target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &obj):Form(obj)
{
	this->_target = obj._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm &obj)
{
	this->_target = obj._target;
	this->_signed = obj._signed;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
	this->is_executable(executor);
	std::ofstream  outfile(this->_target);
	outfile <<
"         &&& &&  & &&                      &&& &&  & && " <<  std::endl <<
"     && &\\/&\\|& ()|/ @, &             && &\\/&\\|& ()|/ @, &" <<  std::endl <<
"    &\\/(/&/&||/& /_/)_&/_&           &\\/(/&/&||/& /_/)_&/_&" <<  std::endl <<
"   &() &\\/&|()|/&\\/ '%' & ()        &() &\\/&|()|/&\\/ '%' & ()" <<  std::endl <<
"  &_\\_&&_\\ |& |&&/&__%_/_& &&      &_\\_&&_\\ |& |&&/&__%_/_& &&" <<  std::endl <<
" &&   && & &| &| /& & % ()& /&&   &&   && & &| &| /& & % ()& /&&" <<  std::endl <<
" ()&_---()&\\&\\|&&-&&--%---()~      ()&_---()&\\&\\|&&-&&--%---()~" <<  std::endl <<
"   &&     \\|||             &&                 \\|||" <<  std::endl <<
"           |||                                 |||" <<  std::endl <<
"           |||                                 |||" <<  std::endl <<
"           |||                                 |||" <<  std::endl <<
", -=-~  .-^- , -=-~  .-^- _, -=-~  .-^- _, -=-~  .-^- _, -=-~  .-^- _, -=-~  .-^- _, -=-~  .-^- _" <<  std::endl;


}
