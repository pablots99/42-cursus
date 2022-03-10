/*



*/


#pragma once
#include <iostream>



class Warlock { 

	public:
		std::string const &getTitle() const{
			return title;
		}
		void setTitle(std::string const &_title ){
			title = _title;
		}
		std::string const & getName()const{
			return name;
		}
		void introduce() const {
			std::cout << name << ": I am " << name << ", " << title << std::endl; 	
		}
		Warlock(std::string const &_name, std::string const &_title):name(_name),title(_title){
			std::cout << name << ": This looks like another boring day." << std::endl;	
		}
		~Warlock() { 
			std::cout << name << ": My job here is done!" << std::endl;
		}
	private:
		std::string name;
		std::string title;

};



