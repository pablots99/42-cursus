/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablo <pablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:48:35 by ptorres           #+#    #+#             */
/*   Updated: 2022/01/14 02:59:09 by pablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "Materia Source" << std::endl;
	std::cout << "--------------" << std::endl;
	MateriaSource *source = new MateriaSource();
	AMateria *ice = new Ice();
	AMateria *cure = new Cure();
	source->learnMateria(ice);
	source->learnMateria(cure);
	std::cout << "--------------" << std::endl;
	std::cout << "Characters    " << std::endl;
	std::cout << "--------------" << std::endl;
	Character *pablo = new Character("Pablo");
	Character *juan = new Character("Juan");
	pablo->equip(source->createMateria("ice"));
	pablo->equip(source->createMateria("cure"));
	pablo->equip(source->createMateria("jajaja"));
	pablo->use(2,*juan);
	pablo->use(1,*juan);
	pablo->unequip(1);
	pablo->use(1,*juan);
	std::cout << "--------------" << std::endl;
	std::cout << "Deep character copy" << std::endl;
	std::cout << "--------------" << std::endl;
	juan->equip(ice);
	*pablo = *juan;
	delete juan;
	std::cout << pablo->getName() << std::endl;
	pablo->use(0,*pablo);
	std::cout << "--------------" << std::endl;
	std::cout << "Destructors    " << std::endl;
	std::cout << "--------------" << std::endl;
	delete cure;
	delete pablo;
	delete	source;
}
