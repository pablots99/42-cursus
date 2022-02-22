/*



*/



#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ATarget("Target Practice Dummy"){

}

Fwoosh::Fwoosh(Fwoosh &obj): ATarget(obj)
{

}

Fwoosh & Fwoosh::operator=(Fwoosh &obj)
{
	(void)obj;
	//FILL HERE
	return *this;
}


ATarget * Fwoosh::clone(){

	return new Fwoosh(*this);
}	




Fwoosh:~Fwoosh(){

}
