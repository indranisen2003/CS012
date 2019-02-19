#include <iostream>
#include <cstdlib>
#include <ctime>

#include "IntVector.h"

using namespace std;

int main(int argc, char *argv[]) {
	cout << "BEGIN TEST" << endl;
	
	srand(time(nullptr));
	
	//Constants
	const int SIZE = rand() % 100 + 1;
	const int INITIAL_VALUE = rand() % 100 + 1;
	const int INSERT_INDEX = rand() % (SIZE / 2) + 1; 
	const int INSERT_VALUE = rand() % 100 + 1;
	
	cout << endl;
	
	//Create vector 1
	cout << "Created empty IntVector." << endl;
	IntVector v1 = IntVector();
	
	cout << endl;
	
	//Test pushback
	cout << "Pushing back " << INITIAL_VALUE << "..." << endl;
	v1.push_back(INITIAL_VALUE);
	cout << "Value: " << v1.at(0) << endl;
	
	cout << endl;
	
	//Create vector 2
	cout << "Created IntVector of size " << SIZE << " with initial value " << INITIAL_VALUE << "." << endl;
	IntVector vector = IntVector(SIZE, INITIAL_VALUE);
	
	cout << endl;
	
	//Test vector size
	cout << "vector.size() = " << vector.size() << endl;
	
	//Test vector capacity
	cout << "vector.capacity() = " << vector.capacity() << endl;
	
	//Test if vector is empty
	cout << "vector.empty() = " << vector.empty() << endl;
	
	cout << endl;
	
	//Test vector iterating
	cout << "Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	
	//Test error throwing for accessing values
	//cout << "Attempting to access index " << vector.size() << "..." << endl;
	//cout << vector.at(vector.size());
	
	cout << endl;
	
	//Test vector insert
	cout << "Inserting " << INSERT_VALUE << " into index " << INSERT_INDEX << "..." << endl;
	vector.insert(INSERT_INDEX, INSERT_VALUE);
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	cout << "New Size: " << vector.size() << endl;
	
	cout << endl;
	
	//Test vector insert
	cout << "Erasing index " << INSERT_INDEX << "..." << endl;
	vector.erase(INSERT_INDEX);
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	cout << "New Size: " << vector.size() << endl;
	
	cout << endl;
	
	//Test vector front
	cout << "First value of vector: " << vector.front() << endl;
	
	//Test vector back
	cout << "Last value of vector: " << vector.back() << endl;
	
	cout << endl;
	
	//Test vector clear
	cout << "Clearing vector..." << endl;
	vector.clear();
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	
	cout << endl;
	
	//Test vector assign
	cout << "Assigning a size of " << SIZE + 10 << " with values of " << INITIAL_VALUE * 2 << "..." << endl;
	vector.assign(SIZE + 10, INITIAL_VALUE * 2);
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	cout << "New Size: " << vector.size() << endl;
	
	cout << endl;
	
	cout << "Pushing back " << INITIAL_VALUE * 4 << "..." << endl;
	vector.push_back(INITIAL_VALUE * 4);
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	cout << "New Size: " << vector.size() << endl;
	
	cout << endl;
	
	cout << "Popping back last value..." << endl;
	vector.pop_back();
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	cout << "New Size: " << vector.size() << endl;
	
	cout << endl;
	
	cout << "Resizing vector to size " << vector.size() + 15 << "..." << endl;
	vector.resize(vector.size() + 15);
	cout << "New Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	cout << "New Size: " << vector.size() << endl;
	
	cout << endl;
	
	cout << "Doubling vector capacity with resize..." << endl;
	cout << "Old capacity: " << vector.capacity() << endl;
	vector.reserve(vector.capacity() * 2);
	cout << "New capacity: " << vector.capacity() << endl;
	
	cout << endl;
	
	cout << "END TEST" << endl;
	
	return 0;
}