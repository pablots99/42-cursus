/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:49:42 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 14:22:31 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef	Klass_HPP
#define Klass_HPP

#include <iostream>


class Klass
{
private:
	/* data */
public:
	Klass();
	Klass(Klass &obj);
	Klass &operator=(Klass &obj);
	~Klass();
};
std::ostream &operator<<(std::ostream &os,Klass const &obj);
#endif

