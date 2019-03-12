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

IntList::IntList(const IntList &cpy) {
	head = nullptr;
	tail = nullptr;
	IntNode* currNode = cpy.head;
	while (currNode != nullptr) {
		push_back(currNode -> data);
		currNode = currNode -> next;
	}
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

void IntList::push_back(int value) {
	IntNode* newNode = new IntNode(value);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		tail -> next = newNode;
		tail = newNode;
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

void IntList::clear() {
	IntNode* currNode = head;
	
	while (currNode != nullptr) {
		IntNode* nextNode = currNode -> next;
		delete currNode;
		currNode = nextNode;
	}
	
	delete currNode;
	
	head = nullptr;
	tail = nullptr;
}

const int & IntList::front() const {
	return head -> data;
}

const int & IntList::back() const {
	return tail -> data;
}

void IntList::selection_sort() {
	IntNode* currNode = head;
	while (currNode != nullptr && currNode -> next != nullptr) {
		IntNode* min = currNode;
		
		for (IntNode* i = currNode -> next; i != nullptr; i = i -> next) {
			if (i -> data < min -> data) {
				min = i;
			}
		}
		
		if (min != currNode) {
			int temp = min -> data;
			min -> data = currNode -> data;
			currNode -> data = temp;
		}
		
		currNode = currNode -> next;
	}
}

void IntList::insert_ordered(int value) {
	IntNode* newNode = new IntNode(value);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else if (head -> data >= newNode -> data) {
		newNode -> next = head;
		head = newNode;
	}
	else if (newNode -> data >= tail -> data) {
		tail -> next = newNode;
		tail = newNode;
	}
	else {
		IntNode* currNode = head;
		while (currNode -> next != nullptr && currNode -> next -> data <= newNode -> data) {
			currNode = currNode -> next;
		}
		newNode -> next = currNode -> next;
		currNode -> next = newNode;
	}
}

void IntList::remove_duplicates() {
	IntNode* currNode = head;
	IntNode* checkNode;
	
	while (currNode != nullptr && currNode -> next != nullptr) {
		checkNode = currNode;
		
		while (checkNode -> next != nullptr) {
			if (currNode -> data == checkNode -> next -> data) {
				IntNode* deleteNode = checkNode -> next;
				checkNode -> next = checkNode -> next -> next;
				delete deleteNode;
				
				if (checkNode -> next == nullptr) {
					tail = checkNode;
				}
			}
			else {
				checkNode = checkNode -> next;
			}
		}
		
		currNode = currNode -> next;
	}
}

IntList & IntList::operator=(const IntList &rhs) {
	if (this == &rhs) {
		return *this;
	}
	else {
		clear();
		
		IntNode* currNode = rhs.head;
		while (currNode != nullptr) {
			push_back(currNode -> data);
			currNode = currNode -> next;
		}
		
		return *this;
	}
}

ostream & operator<<(ostream &out, const IntList &rhs) {
	IntNode* currNode = rhs.head;
	while (currNode != nullptr) {
		if (currNode == rhs.tail) {
			out << currNode -> data;
		}
		else {
			out << currNode -> data << " ";
		}
		currNode = currNode -> next;
	}
	return out;
}