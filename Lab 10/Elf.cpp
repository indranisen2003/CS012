#include <string>
#include <iostream>

using namespace std;

#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, const string &familyName) : Character(HeroType::ELF, name, health, attackStrength) {
	this->familyName = familyName;
}

void Elf::attack(Character &opponent) {
	double damageDealt = (health / MAX_HEALTH) * attackStrength;
	if (opponent.getType() == HeroType::ELF) {
		Elf &opp = dynamic_cast<Elf &> (opponent);
		if (opp.familyName != this -> familyName) {
			opp.damage(damageDealt);
			cout << "Elf " << name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
			cout << opp.getName() << " takes " << damageDealt << " damage." << endl;
		}
		else {
			cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
			cout << "They are both members of the " << familyName << " family." << endl; 
		}
	}
	else {
		opponent.damage(damageDealt);
		cout << "Elf " << name << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
		cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
	}
}