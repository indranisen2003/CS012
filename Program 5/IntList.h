#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>

using namespace std;

struct IntNode {
	int data;
	IntNode* next;
	IntNode(int data) : data(data), next(0) { }
};

class IntList {
 private:
	IntNode* head;
	IntNode* tail;
 public:
	IntList();
	~IntList();
	IntList(const IntList &cpy);
	void display() const;
	void push_front(int);
	void push_back(int);
	void pop_front();
	bool empty() const;
	void clear();
	const int & front() const;
	const int & back() const;
	void selection_sort();
	void insert_ordered(int);
	void remove_duplicates();
	IntList & operator=(const IntList &rhs);
	friend ostream & operator<<(ostream &out, const IntList &rhs);
};

#endif