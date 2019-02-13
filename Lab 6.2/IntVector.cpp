#include <stdexcept>

#include "IntVector.h"

using namespace std;

IntVector::IntVector() {
	sz = 0;
	cap = 0;
	data = nullptr;
}

IntVector::IntVector(unsigned size, int value) {
	sz = size;
	cap = size;
	data = new int[cap];
	for (unsigned int i = 0; i < sz; i++) {
		data[i] = value;
	}
} 

IntVector::~IntVector() {
	delete data;
}

unsigned IntVector::size() const {
	return sz;
}

unsigned IntVector::capacity() const {
	return cap;
}

bool IntVector::empty() const {
	return sz == 0;
}

const int & IntVector::at(unsigned index) const {
	if (index >= sz || index < 0) {
		throw out_of_range("IntVector::at_range_check");
	}
	else {
		return data[index];
	}
}

const int & IntVector::front() const {
	return data[0];
}

const int & IntVector::back() const {
	return data[sz - 1];
}