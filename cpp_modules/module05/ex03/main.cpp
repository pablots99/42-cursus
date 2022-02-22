/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:08:33 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 22:01:07 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern *intern =  new Intern();
	Bureaucrat *bureau = new Bureaucrat("Master",1);
	Form *form;
	std::cout << *bureau << std::endl;
	form = intern->makeForm("robotomy request", "brain");
	if(!form)
		return 0;
	std::cout << *form << std::endl;
	delete form;
	form  = intern->makeForm("presidential pardon", "brain");
	std::cout << *form << std::endl;
	delete form;
	form  = intern->makeForm("presidentiaaa pardon", "brain");
	std::cout << form << std::endl;
	delete bureau;
}
