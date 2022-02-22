ynta*



*/



#include "ATarget.hpp"

ATarget::ATarget(std::string const type):_type(type){

	
}


ATarget::ATarget(ATarget &obj)
{
	*this = obj;
}

ATarget & ATarget::operator=(ATarget &obj)
{
	(void)obj;
	//FILL HERE
	return *this;
}


const std::string &ATarget::getType() const {
	return _type;
}
void ATarger::getHitByspell(ASpell const &ref)
{

	std::cout << _type << " has been " << _effects <<"!" << std::endl;

}




ATarget:~ATarget(){

}
