/*


*/

#ifndef Warlock_HPP
#define Warlock_HPP
#include <iostream>


class Warlock { 

	private:
		std::string _name;
		std::string _title;			
	public:
		Warlock(std::string name, std::string title);
		//WarlockS(CLASS &obj);
		//Warlock &operator=(CLASS &obj);
		~Warlock();
		void introduce() const;
		const	std::string &getName() const ;
		const std::string &getTitle() const;
		void setTitle(const std::string &title);
};



#endif
