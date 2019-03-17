#ifndef WARRIOR_H
#define WARRIOR_H

#include<string>

using namespace std;

#include "Character.h"

class Warrior : public Character {
	protected:
		string allegiance;
	
	public:
		Warrior(const string &, double, double, const string &);
		virtual void attack(Character &);
};

#endif