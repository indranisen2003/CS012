#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

#include "Deck.h"
#include "Card.h"

using namespace std;

ostream & operator<<(ostream &out, const vector<Card> deck) {
	for (unsigned int i = 0; i < deck.size(); i++) {
		if (i != deck.size() - 1) {
			out << deck.at(i) << ", ";
		}
		else {
			out << deck.at(i);
		}
	}
	return out;
}

bool hasPair(vector<Card> cards) {
	for (unsigned int i = 0; i < cards.size(); i++) {
		for (unsigned int j = i + 1; j < cards.size(); j++) {
			if (cards.at(i).getRank() == cards.at(j).getRank()) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	srand(2222);
	
	ofstream out;
	
	string outputDecision, outputFile;
	unsigned int numCards, deals;
	int pairs = 0;
	
	vector<Card> dealt;
	Deck deck = Deck();
	
	cout << "Do you want to output all hands to a file?(Yes/No) " << endl;
	cin >> outputDecision;
	
	if (outputDecision == "Yes") {
		cout << "Enter name of output file: " << endl;
		cin >> outputFile;
		out.open(outputFile);
		if (!out.is_open()) {
			cout << "Could not open " << outputFile << "." << endl;
			exit(1);
		}
	}
	
	cout << "Enter number of cards per hand: " << endl;
	cin >> numCards;
	
	cout << "Enter number of deals (simulations): " << endl;
	cin >> deals;
	
	for (unsigned int i = 0; i < deals; i++) {
		deck.shuffleDeck();
		dealt.clear();
		
		for (unsigned int j = 0; j < numCards; j++) {
			dealt.push_back(deck.dealCard());
		}
		
		if (hasPair(dealt)) {
			pairs++;
			out << "Found Pair!!";
		}
		else {
			out << "             ";
		}
		
		out << dealt << endl;
	}

	out.close();
	
	double chance = (static_cast<double>(pairs) / deals) * 100;
	cout << "Chances of receiving a pair in a hand of " << numCards << " cards is: " << chance << "%" << endl;
}
