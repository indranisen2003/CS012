#ifndef INTLIST_H
#define INTLIST_H

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
	void display() const;
	void push_front(int);
	void pop_front();
	bool empty() const;
	const int & front() const;
	const int & back() const;
};

#endif

