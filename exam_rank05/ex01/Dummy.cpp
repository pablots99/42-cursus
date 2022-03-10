/**/




#include "Dummy.hpp"




ATarget * Dummy::clone() const {

	return new Dummy(*this);
}
