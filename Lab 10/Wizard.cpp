#include <string>
#include <iostream>

using namespace std;

#include "Wizard.h"

Wizard::Wizard(const string &name, double health, double attackStrength, int rank) : Character(HeroType::WIZARD, name, health, attackStrength) {
	this->rank = rank;
}

void Wizard::attack(Character &opponent) {
	if (opponent.getType() == HeroType::WIZARD) {
		Wizard &opp = dynamic_cast<Wizard &> (opponent);
		double damageDealt = (static_cast<double> (rank)/ opp.rank) * attackStrength;
		opp.damage(damageDealt);
		cout << "Wizard " << name << " attacks " << opp.getName() << " --- POOF!!" << endl;
		cout << opp.getName() << " takes " << damageDealt << " damage." << endl;
	}
	else {
		opponent.damage(attackStrength);
		cout << "Wizard " << name << " attacks " << opponent.getName() << " --- POOF!!" << endl;
		cout << opponent.getName() << " takes " << attackStrength << " damage." << endl;
	}
}