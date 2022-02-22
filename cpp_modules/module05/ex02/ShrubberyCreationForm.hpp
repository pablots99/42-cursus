/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:52:16 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include <iostream>
#include "Form.hpp"

class ShrubberyCreationForm: public Form
{
private:
		std::string  _target;
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &obj);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm &obj);
	~ShrubberyCreationForm();
	void execute( const Bureaucrat &executor) const;
};
#endif

