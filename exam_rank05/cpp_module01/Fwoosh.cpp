/*



*/



#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): Aspell("Fwoosh", "fwooshed"){

}

Fwoosh::Fwoosh(Fwoosh &obj): ASepell(obj)
{

}

Fwoosh & Fwoosh::operator=(Fwoosh &obj)
{
	(void)obj;
	//FILL HERE
	return *this;
}


ASpell * Fwoosh::clone(){

	return new Fwoosh(*this);
}	




Fwoosh:~Fwoosh(){

}
