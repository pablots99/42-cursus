/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:25 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:51:52 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class Bureaucrat;

#include <iostream>
#include <ostream>
#include "Form.hpp"



class Bureaucrat
{

class GradeTooHighException: public std::exception
{
	const char * what () const throw()
	{
		return "The grade is to hi! maximun value is 1";
	}
};
class GradeTooLowException: public std::exception
{

	const char * what () const throw()
	{
		return "The grade is to low! minimum value is 150";
	}
};

private:
	int _grade;
	const std::string _name;
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &obj);
	Bureaucrat &operator=(Bureaucrat &obj);
	~Bureaucrat();
	std::string getName() const ;
	int getGrade() const;
	void incremetGrade();
	void decrementGrade();
	void signForm(Form  &form) const;
	void executeForm(Form const &form) const ;
};
std::ostream &operator<<(std::ostream &os,Bureaucrat const &b);

#endif
