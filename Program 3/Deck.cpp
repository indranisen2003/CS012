#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

#include "Deck.h"
#include "Card.h"

using namespace std;

Deck::Deck() {
	char s = 's';
	for (unsigned int i = 13; i > 0; i--) {
		theDeck.push_back(Card(s, i));
	}
	
	s = 'h';
	for (unsigned int i = 13; i > 0; i--) {
		theDeck.push_back(Card(s, i));
	}
			
	s = 'd';
	for (unsigned int i = 13; i > 0; i--) {
		theDeck.push_back(Card(s, i));
	}
				
	s = 'c';
	for (unsigned int i = 13; i > 0; i--) {
		theDeck.push_back(Card(s, i));
	}	
}

Card Deck::dealCard() {
	Card c = theDeck.at(theDeck.size() - 1);
	theDeck.pop_back();
	dealtCards.push_back(c);
	return c;
}

void Deck::shuffleDeck() {
	for (unsigned int i = 0; i < dealtCards.size(); i++) {
		theDeck.push_back(dealtCards.at(i));
	}
	dealtCards.clear();
 	random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const {
	return theDeck.size();
}