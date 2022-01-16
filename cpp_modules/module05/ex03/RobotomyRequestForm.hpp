/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:51:57 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	RobotomyRequestForm_HPP
#define RobotomyRequestForm_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
private:
		std::string  _target;
		static int   _times_executed;
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &obj);
	RobotomyRequestForm &operator=(RobotomyRequestForm &obj);
	~RobotomyRequestForm();
	void execute( const Bureaucrat &executor) const;
};
#endif

