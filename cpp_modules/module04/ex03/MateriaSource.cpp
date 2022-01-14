/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:46:51 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 02:35:58 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"



MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		this->_learned[i] = NULL;
	std::cout << "Materia source constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &obj)
{
	for (size_t i = 0; i < 4; i++)
	{

		if(this->_learned[i])
			delete _learned[i];
		if(obj._learned[i])
			this->_learned[i] = obj._learned[i]->clone();
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource &obj)
{
	for (size_t i = 0; i < 4; i++)
	{
		if(this->_learned[i])
			delete _learned[i];
		if(obj._learned[i])
			this->_learned[i] = obj._learned[i]->clone();
	}
	return *this;
}


MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if(this->_learned[i])
			delete _learned[i];
	}
	std::cout << "Materia source destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while(this->_learned[i] && i < 4)
		i++;
	if(i == 4)
	{
		std::cout << "Cannot learn more materia"<< std::endl;
		return ;
	}
	this->_learned[i] = m->clone();
	std::cout << "MAteria "<< m->getType() << " learned!" << std::endl;
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if(this->_learned[i] && this->_learned[i]->getType() == type)
			return this->_learned[i]->clone();
	}
	return 0;
}
