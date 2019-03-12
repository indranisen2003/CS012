#include <iostream>

using namespace std;

#include "SortedSet.h"

SortedSet::SortedSet() : IntList() {}

SortedSet::SortedSet(const SortedSet &set) : IntList(set) {
	
}

SortedSet::SortedSet(const IntList &list) : IntList(list) {
	IntList::remove_duplicates();
	IntList::selection_sort();
}

SortedSet::~SortedSet() {}

bool SortedSet::in(int data) {
	IntNode* currNode = head;
	while (currNode != nullptr) {
		if (currNode -> data == data) {
			return true;
		}
		currNode = currNode -> next;
	}
	return false;
}

SortedSet & SortedSet::operator|(SortedSet &set) {
	SortedSet* sset = new SortedSet();
	if (set.head == nullptr) {
		sset = this;
	}
	else if (head == nullptr) {
		sset = &set;
	}
	else {
		IntNode* nodeA = head;
		IntNode* nodeB = set.head;
		
		if (nodeA -> data < nodeB -> data) {
			sset -> push_back(nodeA -> data);
			nodeA = nodeA -> next;
		}
		else {
			sset -> push_back(nodeB -> data);
			nodeB = nodeB -> next;
		}
		
		while (nodeA != nullptr && nodeB != nullptr) {
			if (nodeA -> data < nodeB -> data) {
				sset -> push_back(nodeA -> data);
				nodeA = nodeA -> next;
			}
			else {
				sset -> push_back(nodeB -> data);
				nodeB = nodeB -> next;
			}
		}
		
		if (nodeA != nullptr) {
			while (nodeA != nullptr) {
				sset -> push_back(nodeA -> data);
				nodeA = nodeA -> next;
			}
		}
		else {
			while (nodeB != nullptr) {
				sset -> push_back(nodeB -> data);
				nodeB = nodeB -> next;
			}
		}
	}
	return *sset;
}

SortedSet & SortedSet::operator&(SortedSet &set) {
	SortedSet* sset = new SortedSet();
	
	IntNode* currNode = head;
	while (currNode != nullptr) {
		if (in(currNode -> data) && set.in(currNode -> data)) {
			sset -> push_back(currNode -> data);
		}
		currNode = currNode -> next;
	}
	
	currNode = set.head;
	while (currNode != nullptr) {
		if (in(currNode -> data) && set.in(currNode -> data) && !sset -> in(currNode -> data)) {
			sset -> push_back(currNode -> data);
		}
		currNode = currNode -> next;
	}
	
	return *sset;
}

void SortedSet::add(int data) {
	IntNode* newNode = new IntNode(data);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else if (head -> data > newNode -> data) {
		newNode -> next = head;
		head = newNode;
	}
	else if (newNode -> data > tail -> data) {
		tail -> next = newNode;
		tail = newNode;
	}
	else {
		bool shouldAdd = true;
		IntNode* currNode = head;
		while (currNode -> next != nullptr && currNode -> next -> data <= newNode -> data) {
			if (currNode -> next -> data == data) {
				shouldAdd = false;
			}
			currNode = currNode -> next;
		}
		if (shouldAdd) {
			newNode -> next = currNode -> next;
			currNode -> next = newNode;
		}
	}
}

void SortedSet::push_front(int data) {
	add(data);
}

void SortedSet::push_back(int data) {
	add(data);
}

void SortedSet::insert_ordered(int data) {
	add(data);
}

SortedSet & SortedSet::operator|=(SortedSet &set) {
	if (set.head != nullptr) {
		SortedSet* sset = new SortedSet();
		sset = &(*this | set);
		
		this -> clear();
		
		IntNode* currNode = sset -> head;
		while (currNode != nullptr) {
			this -> push_back(currNode -> data);
			currNode = currNode -> next;
		}
		
		return *sset;
	}
	else {
		return *this;
	}
}

SortedSet & SortedSet::operator&=(SortedSet &set) {
	SortedSet* sset = &(*this & set);
	
	this -> clear();
	
	IntNode* currNode = sset -> head;
	while (currNode != nullptr) {
		this -> push_back(currNode -> data);
		currNode = currNode -> next;
	}
	
	return *sset;
}