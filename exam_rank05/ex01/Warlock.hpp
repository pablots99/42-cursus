/*



*/


#pragma once
#include <iostream>
#include <map>
#include "ASpell.hpp"
#include <utility> 
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
		void learnSpell(ASpell const*sp) { 
			if(spells.find(sp->getName()) != spells.end())	{
				spells.insert(std::make_pair(sp->getName(),sp));
			}
		}
		void forgetSpell(std::string const n){
			 if(spells.find(n) != spells.end())    {
				spells.erase(n);
			}
		}
		
		void launchSpell(std::string const sp, ATarget const &target) { 
			
			if(spells.find(sp) != spells.end())    {
				spells[sp]->launchSpell(target);
			}
		}


		~Warlock() { 
			std::cout << name << ": My job here is done!" << std::endl;
			spells.erase(spells.begin(),spells.end());
		}
	private:
		std::string name;
		std::string title;
		std::map<const std::string,const ASpell *> spells;

};


		
