/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:08:33 by pablo             #+#    #+#             */
/*   Updated: 2022/01/16 19:25:47 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form *form = new Form("Form 1 ",30,50);
	Form *form2 = new Form("Form 2 ",30,50);
	Bureaucrat * pablo =  new Bureaucrat("Pablo", 10);
	Bureaucrat * juan =  new Bureaucrat("Juan",100);


	std::cout << *pablo << std::endl;
	std::cout << *juan << std::endl;
	std::cout << *form << std::endl;
	juan->signForm(*form);
	pablo->signForm(*form);
	pablo->signForm(*form);
	form2->beSigned(*pablo);
	delete form;
	delete pablo;
	delete juan;
	return 0;
}
