#include <iostream>
#include <cctype>

#include "Card.h"

using namespace std;

Card::Card() {
	suit = 'c';
	rank = 2;
}

Card::Card(char s, int r) {
	char c = tolower(s);
	if (c == 'c' || c == 'd' || c == 's' || c == 'h') {
		suit = c;
	}
	else {
		suit = 'c';
	}
	
	if (r > 13 || r < 1) {
		rank = 2;
	}
	else {
		rank = r;
	}
}

char Card::getSuit() const {
	return suit;
}

int Card::getRank() const {
	return rank;
}

ostream & operator<<(ostream &out, const Card &card) {
	if (card.getRank() == 11) {
		out << "Jack of ";
	}
	else if (card.getRank() == 12) {
		out << "Queen of ";
	}
	else if (card.getRank() == 13) {
		out << "King of ";
	}
	else if (card.getRank() == 1) {
		out << "Ace of ";
	}
	else {
		out << card.getRank() << " of ";
	}
	
	if (card.getSuit() == 'c') {
		out << "Clubs";
	}
	else if (card.getSuit() == 'd') {
		out << "Diamonds";
	}
	else if (card.getSuit() == 's') {
		out << "Spades";
	}
	else if (card.getSuit() == 'h') {
		out << "Hearts";
	}
	
	return out;
}