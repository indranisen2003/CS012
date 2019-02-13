#include <iostream>
#include <cstdlib>
#include <ctime>

#include "IntVector.h"

using namespace std;

int main(int argc, char *argv[]) {
	srand(time(nullptr));
	
	//Size and initial capacity
	const int SIZE = rand() % 100 + 1;
	const int INITIAL_VALUE = rand() % 100 + 1;
	
	//Create vector
	cout << "Created IntVector of size " << SIZE << " with initial value " << INITIAL_VALUE << "." << endl;
	IntVector vector = IntVector(SIZE, INITIAL_VALUE);
	
	//Test vector size
	cout << "vector.size() = " << vector.size() << endl;
	
	//Test vector capacity
	cout << "vector.capacity() = " << vector.capacity() << endl;
	
	//Test if vector is empty
	cout << "vector.empty() = " << vector.empty() << endl;
	
	
	//Test vector iterating
	cout << "Values: ";
	for (unsigned int i = 0; i < vector.size(); i++) {
		cout << vector.at(i) << " ";
	}
	cout << endl;
	
	//Test error throwing for accessing values
	//cout << "Attempting to access index " << vector.size() << "..." << endl;
	//cout << vector.at(vector.size());
	
	
	//Test vector front
	cout << "First value of vector: " << vector.front() << endl;
	
	//Test vector back
	cout << "Last value of vector: " << vector.back() << endl;
	
}