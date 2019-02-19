#ifndef __INTVECTOR_H__
#define __INTVECTOR_H__

using namespace std;

class IntVector {
	private:
		unsigned sz; //stores the size of the IntVector (the number of elements currently being used)
		unsigned cap; //store the size of the array
		int *data; //stores the address of the dynamically-allocated array of integers
		
		void expand(); //doubles capacity of array
		void expand(unsigned amount); //expands the array by amount
	public:
		IntVector(); //sets both the size and capacity of the IntVector to 0 and will not allocate any memory to store integers
		IntVector(unsigned size, int value = 0); //Sets sz and cap to size and fills data with sz amount of value integers
		~IntVector(); //deletes data
		
		unsigned size() const; //returns size
		unsigned capacity() const; //returns capacity
		bool empty() const; //returns true if data is empty
		
		const int & at(unsigned index) const; //returns value at index
		int & at(unsigned index); //non const version of at
		
		void insert(unsigned index, int value); //inserts value at position index
		
		void erase(unsigned index); //removes value at position index
		
		const int & front() const; //returns first value
		int & front(); //non const version of front
		
		const int & back() const; //returns last value
		int & back(); //non const version of back
		
		void assign(unsigned n, int value); //sets size to n and fill with value
		
		void push_back(int value); //inserts value at back
		void pop_back(); //removes last element
		
		void clear(); //clears the array
		
		void resize(unsigned size, int value = 0); //resizes vector to contain size elements; appends appropirate amount of value
		
		void reserve(unsigned n); //requests that the capacity (the size of the dynamically allocated array) be set to n at minimum
};

#endif