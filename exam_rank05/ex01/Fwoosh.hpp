/*




*/


#pragma once

#include "ASpell.hpp"



class Fwoosh : public ASpell {
	public:
		Fwoosh():ASpell("Fwoosh","Fwooshed") {}
		virtual ~Fwoosh(){};
		virtual ASpell *clone() const;


};
