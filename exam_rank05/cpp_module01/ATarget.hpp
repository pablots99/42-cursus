/*


*/

#ifndef ATarget_HPP
#define ATarget_HPP


#include <iostream>
#include "ASpell.hpp"

class ATarget { 

	protected:
			std::string const _type;
	public:
		ATarget(std::string const type);
		ATargetS(Atarget &obj);
		ATarget &operator=(Atarget &obj);
		virtual ~ATarget();
		const std::string &getType() const;
		virtual *ATarget clone() const = 0;
		void getHitBySpell(ASpell const & ref);
}



#endif
