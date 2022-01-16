/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:25 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 21:04:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

class Form;


#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"


class Form
{
class GradeTooHighException: public std::exception
{
	const char * what () const throw()
	{
		return "The grade is to hi!";
	}
};
class GradeTooLowException: public std::exception
{
	const char * what () const throw()
	{
		return "The grade is to low!";
	}
};
class FormSignedException: public std::exception
{

	const char * what () const throw()
	{
		return "Form Alredy signed";
	}
};
class FormNotSignedException: public std::exception
{

	const char * what () const throw()
	{
		return "Form is not signed";
	}
};

protected:
	const std::string _name;
	const int _sign_req;
	const int _exec_req;
	bool _signed;
public:
	Form(std::string name, int sign_req, int exec_req);
	Form(Form &obj);
	Form &operator=(Form &obj);
	virtual ~Form();
	std::string getName() const;
	void beSigned(Bureaucrat const  &b);
	int getSign_req() const;
	int getExec_req() const;
	bool getSigned()  const;
	virtual void execute( const Bureaucrat &executor) const;
	void is_executable(Bureaucrat const &executor ) const;
};
std::ostream &operator<<(std::ostream &os,Form const &obj);

#endif
