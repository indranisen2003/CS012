#ifndef ELF_H
#define ELF_H

#include<string>

using namespace std;

#include "Character.h"

class Elf : public Character {
	protected:
		string familyName;
	
	public:
		Elf(const string &, double, double, const string &);
		virtual void attack(Character &);
};

#endif