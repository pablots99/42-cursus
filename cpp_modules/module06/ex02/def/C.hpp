/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptorres <ptorres@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/18 18:18:18 by ptorres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	C_HPP
#define C_HPP

#include <iostream>
#include "Base.hpp"


class C: public Base
{
private:
	/* data */
public:
	C(void);
	C(C &obj);
	C &operator=(C &obj);
	~C();
};
#endif

