/*



*/



#include "ASpell.hpp"

ASpell::Aspell(std::string name, std::string effects):_name(name),_effects(effects)
{
	
}

ASpell::ASpell(CLASS &obj)
{
	*this = obj;
}

ASpell & ASpell::operator=(CLASS &obj)
{
	(void)obj;
	//FILL HERE
	return *this;
}

const std::string getName() const { 

	return _name;
}

const std::string getEffects() const { 
	return _effects;
}

ASpell:~ASpell(){

}
