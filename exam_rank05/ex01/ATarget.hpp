/*




*/



#pragma once

#include <iostream>



class ASpell;


class ATarget { 

	public:
		std::string const &getType() const{
			return type;
		}
		virtual ATarget*clone(void) const = 0;
		ATarget(void){}
		ATarget(std::string _type):type(_type) { }
		ATarget(ATarget &obj):type(obj.getType()){}
		ATarget &operator=(ATarget &obj) {
			type = obj.getType();
			return *this;
		}
		virtual ~ATarget(){}

		void getHitBySpell(ASpell const &spell)	const;
	protected:
		std::string type;

};

