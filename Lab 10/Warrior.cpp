#include <string>
#include <iostream>

using namespace std;

#include "Warrior.h"

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance) : Character(HeroType::WARRIOR, name, health, attackStrength) {
	this->allegiance = allegiance;
}

void Warrior::attack(Character &opponent) {
	double damageDealt = (health / MAX_HEALTH) * attackStrength;
	if (opponent.getType() == HeroType::WARRIOR) {
		Warrior &opp = dynamic_cast<Warrior &> (opponent);
		if (opp.allegiance != allegiance) {
			opp.damage(damageDealt);
			cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
			cout << opp.getName() << " takes " << damageDealt << " damage." << endl;
		}
		else {
			cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
			cout << "They share an allegiance with " << allegiance << "." << endl;
		}
	}
	else {
		opponent.damage(damageDealt);
		cout << "Warrior " << name << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
		cout << opponent.getName() << " takes " << damageDealt << " damage." << endl;
	}
}