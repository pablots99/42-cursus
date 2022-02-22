/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:08:25 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 19:21:32 by pablo            ###   ########.fr       */
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

private:
	const std::string _name;
	const int _sign_req;
	const int _exec_req;
	bool _signed;
public:
	Form(std::string name, int sign_req, int exec_req);
	Form(Form &obj);
	Form &operator=(Form &obj);
	~Form();
	std::string getName() const;
	void beSigned(Bureaucrat &b);
	int getSign_req() const;
	int getExec_req() const;
	bool getSigned()  const;

};
std::ostream &operator<<(std::ostream &os,Form const &obj);

#endif
