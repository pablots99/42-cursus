/*


*/

#ifndef ASpell_HPP
#define ASpell_HPP

#include <iostream>

#include "ATarget.hpp"

class ASpell { 

	protected:
		const std::string _name;
		const std::string _effects;
	public:
		ASpell();
		ASpell(std::string name, std::string effects):
		ASpellS(CLASS &obj);
		ASpell &operator=(CLASS &obj);
		virtual ~ASpell();
		const std::string &getName() const;
		const std::string &getEffects() const;
		virtual Aspell *clone() const = 0;
		void launch(ATarget const  &ref) const;


}



#endif
