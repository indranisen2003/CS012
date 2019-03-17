#ifndef WIZARD_H
#define WIZARD_H

#include<string>

using namespace std;

#include "Character.h"

class Wizard : public Character {
	protected:
		int rank;
	
	public:
		Wizard(const string &, double, double, int);
		virtual void attack(Character &);
};

#endif