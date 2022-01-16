/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 21:34:44 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	Intern_HPP
#define Intern_HPP

#include <iostream>
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern &obj);
	~Intern();
	Form * makeForm(std::string name, std::string target);
};
std::ostream &operator<<(std::ostream &os,Intern const &obj);
#endif

