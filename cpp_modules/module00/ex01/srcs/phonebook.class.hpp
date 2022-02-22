/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 11:14:49 by pablo             #+#    #+#             */
/*   Updated: 2021/09/21 13:36:59 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "contact.class.hpp"

#include <iostream>
#include <iomanip>

class Phonebook {

public:
	Phonebook();
	void add_contact();
	void printContacts( void );
	~Phonebook();

private:
	Contact contacts[8];
	int count;
};

#endif
