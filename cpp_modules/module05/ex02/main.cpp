/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:08:33 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 21:07:25 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	Bureaucrat *master = new Bureaucrat("Master",1);
	Bureaucrat *pablo = new Bureaucrat("Pablo",50);
	Form *shuberry = new ShrubberyCreationForm("shuberry");
	Form  *robotomy =  new RobotomyRequestForm("robotomy");
	Form *presidential = new PresidentialPardonForm("President");

	std::cout << *master << std::endl;
	std::cout << *pablo << std::endl;
	std::cout << *shuberry << std::endl;
	std::cout << *robotomy << std::endl;
	std::cout << *presidential << std::endl;

	//try to execute from form
	std::cout << "----------------------" << std::endl;
	try
	{
		shuberry->execute(*master);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//try to executo from  bureaucrat
	try
	{
		pablo->executeForm(*shuberry);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//sign forms with master
	try
	{
		master->signForm(*shuberry);
		master->signForm(*robotomy);
		master->signForm(*presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//try executing
	try
	{
		pablo->executeForm(*shuberry);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//try executing
	try
	{
		pablo->executeForm(*robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//try executing
	try
	{
		pablo->executeForm(*presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//try executing
	try
	{
		master->executeForm(*robotomy);
		master->executeForm(*robotomy);
		master->executeForm(*robotomy);
		master->executeForm(*robotomy);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	//try executing
	try
	{
		master->executeForm(*presidential);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "----------------------" << std::endl;
	delete pablo;
	delete master;
	delete shuberry;
	delete robotomy;
	delete presidential;
}
