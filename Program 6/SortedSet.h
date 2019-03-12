#ifndef SORTEDSET_H
#define SORTEDSET_H

#include <ostream>

using namespace std;

#include "IntList.h"

class SortedSet : public IntList {
	public:
		SortedSet();
		SortedSet(const SortedSet &);
		SortedSet(const IntList &);
		~SortedSet();
	
		bool in(int data);
		SortedSet & operator|(SortedSet &);
		SortedSet & operator&(SortedSet &);
		
		void add(int data);
		void push_front(int data);
		void push_back(int data);
		void insert_ordered(int data);
		
		SortedSet & operator|=(SortedSet &);
		SortedSet & operator&=(SortedSet &);
};

#endif