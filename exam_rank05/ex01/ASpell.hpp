/*




*/



#pragma once

#include <iostream>
#include "ATarget.hpp"
class ATarget;

class ASpell { 

	public:
		std::string const &getName() const {
			return name;
		}
		
		std::string const &getEffects() const {
			return effects;
		}
		virtual ASpell*clone(void) const = 0;
		ASpell(void){}
		ASpell(std::string _name, std::string _effects):name(_name),effects(_effects) { }
		ASpell(ASpell &obj):name(obj.getName()),effects(obj.getEffects()){}
		ASpell &operator=(ASpell &obj) {
			name = obj.getName();
			effects = obj.getEffects(); 
			return *this;
		}
		void launchSpell(ATarget const &target) const{
			target.getHitBySpell(*this);
		}
		virtual ~ASpell(){}		
	protected:
		std::string name;
		std::string	 effects;

};
