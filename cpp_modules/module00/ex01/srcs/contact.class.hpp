/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:45:32 by pablo             #+#    #+#             */
/*   Updated: 2021/11/02 16:32:07 by pablo            ###   ########.fr       */
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
	string _firstName;
	string _lastName;
	string _nickName;
	string _phone;
	string _secret;
};

#endif

