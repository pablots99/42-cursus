/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:45:32 by pablo             #+#    #+#             */
/*   Updated: 2021/12/20 14:25:34 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iomanip>
#include <iostream>

class Contact {
public:
	Contact();
	void setContact( void );
	void printContact( void );
	void printTableContact( int i );
	~Contact();
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickName;
	std::string _phone;
	std::string _secret;
};

#endif

