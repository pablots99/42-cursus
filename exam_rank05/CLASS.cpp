/*



*/



#include "CLASS.hpp"

CLASS::CLASS(){

	
}

CLASS::CLASS(CLASS &obj)
{
	*this = obj;
}

CLASS & CLASS::operator=(CLASS &obj)
{
	(void)obj;
	//FILL HERE
	return *this;
}



CLASS:~CLASS(){

}
