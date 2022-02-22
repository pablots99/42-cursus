/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/18 18:21:26 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	Base_HPP
#define Base_HPP

#include <iostream>


class Base
{
private:
	/* data */
public:
	virtual ~Base();
};

void identify(Base* p);
Base * generate(void);
void identify(Base& p);


#endif

