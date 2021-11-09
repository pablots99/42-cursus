/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:18:44 by pablo             #+#    #+#             */
/*   Updated: 2021/11/02 18:25:26 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){

	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	std::cout << "pointer:		" << stringPTR<< std::endl;
	std::cout << "ref: 			" << &stringREF<< std::endl;
	std::cout << "disp pointer:		" << *stringPTR<< std::endl;
	std::cout << "disp ref:		" << stringREF<< std::endl;


}
