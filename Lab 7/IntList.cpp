#include <iostream>

using namespace std;

#include "IntList.h"

IntList::IntList() {
	head = nullptr;
	tail = nullptr;
}

IntList::~IntList() {
	IntNode* currNode = head;
	while (currNode != nullptr) {
		IntNode* nextNode = currNode -> next;
		delete currNode;
		currNode = nextNode;
	}
	delete currNode;
}

void IntList::display() const {
	IntNode* currNode = head;
	while (currNode != nullptr) {
		if (currNode == tail) {
			cout << currNode -> data;
		}
		else {
			cout << currNode -> data << " ";
		}
		currNode = currNode -> next;
	}
}

void IntList::push_front(int value) {
	if (head == nullptr) {
		IntNode* newNode = new IntNode(value);
		head = newNode;
		tail = newNode;
	}
	else {
		IntNode* newNode = new IntNode(value);
		newNode -> next = head;
		head = newNode;
	}
}

void IntList::pop_front() {
	if (head != nullptr) {
		if (head -> next != nullptr) {
			IntNode* currNode = head;
			delete head;
			head = currNode -> next;
		}
		else {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
	}
}

bool IntList::empty() const {
	return head == nullptr;
}

const int & IntList::front() const {
	return head -> data;
}

const int & IntList::back() const {
	return tail -> data;
}