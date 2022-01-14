/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:47:06 by pablo             #+#    #+#             */
/*   Updated: 2022/01/14 02:17:54 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MATERIA_SOURCE
#define	MATERIA_SOURCE

#include "IMateriaSource.hpp"



class MateriaSource: public IMateriaSource
{
private:
	AMateria *_learned[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource &obj);
	MateriaSource &operator=(MateriaSource &obj);
	~MateriaSource();
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const & type);
};

#endif
