/*


*/

#ifndef Fwoosh_HPP
#define Fwoosh_HPP

#include "ASpell.hpp"

class Fwoosh : public ASpell { 

	private:
		//text here
	public:
		Fwoosh();
		FwooshS(Fwoosh &obj);
		Fwoosh &operator=(Fwoosh &obj);
		ASpell * clone() const;
		~Fwoosh();
}



#endif
