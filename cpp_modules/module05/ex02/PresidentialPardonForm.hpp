/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 20:22:43 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
private:
		std::string  _target;
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &obj);
	PresidentialPardonForm &operator=(PresidentialPardonForm &obj);
	~PresidentialPardonForm();
	void execute( const Bureaucrat &executor) const;
};
#endif

