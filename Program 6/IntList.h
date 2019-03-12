#ifndef INTLIST_H
#define INTLIST_H

#include <ostream>

using namespace std;

struct IntNode {
	int data;
	IntNode* next;
	IntNode(int data) : data(data), next(0) { }
};

class IntList {

 protected:

	IntNode *head;
	IntNode *tail;

 public:

	IntList();
	IntList(const IntList &);
	IntList & operator=(const IntList &);
	~IntList();
	bool empty() const;
	void display() const;
	void push_front(int);
	void push_back(int);
	void pop_front();
	void selection_sort();
	void insert_ordered(int);
	void remove_duplicates();
	void clear();
	friend ostream & operator<<(ostream &, const IntList &);

 private:

   // Used by selection_sort function.
   // Just have this function return nullptr if you don't use this function. 
	IntNode * min(IntNode*);
	
	// Used by copy constructor and/or copy assignment operator.
	// Just implement an empty function if you don't use this function.
	void copy(const IntList &);
};

#endif

