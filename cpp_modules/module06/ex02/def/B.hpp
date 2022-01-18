/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/18 18:18:24 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	B_HPP
#define B_HPP

#include <iostream>
#include "Base.hpp"


class B: public Base
{
private:
	/* data */
public:
	B(void);
	B(B &obj);
	B &operator=(B &obj);
	~B();
};
#endif

