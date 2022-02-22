/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:12:21 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 22:00:36 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <map>
Intern::Intern() {
	std::cout<< "intern constructor called" << std::endl;
}
Intern::Intern(Intern &obj)
{
	*this = obj;
}

Intern::~Intern(){
	std::cout << "Intern destructor called";
}

Form  *Intern::makeForm(std::string name, std::string target)
{
	Form *res ;
	std::map<std::string,Form *> map;
	std::map<std::string,Form *>::iterator i;
	map["robotomy request"] = new  RobotomyRequestForm(target);
	map["presidential pardon"] = new  PresidentialPardonForm(target);
	map["shubberry cration"] = new  ShrubberyCreationForm(target);
	res = map[name];
	for(i=map.begin(); i != map.end(); i++)
	{
		if(i->first != name)
			delete	i->second;
	}
	if(res)
		return res;

	std::cout << "cannot make form: " << name << std:: endl;
	return NULL;
}
