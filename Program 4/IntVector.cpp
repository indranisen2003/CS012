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
	delete[] data;
}

void IntVector::expand() {
	if (cap != 0 && sz != 0) {
		cap *= 2;
		int* newData = new int[cap];
		for (unsigned int i = 0; i < sz; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	else {
		cap = 1;
		sz = 1;
		if (data == nullptr) {
			data = new int[1];
		}
	}
}

void IntVector::expand(unsigned amount) {
	if (cap != 0 && sz != 0) {
		cap += amount;
		int* newData = new int[cap];
		for (unsigned int i = 0; i < sz; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	else {
		cap = 1;
		sz = 1;
		if (data == nullptr) {
			data = new int[1];
		}
	}
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
	if (index >= sz) {
		throw out_of_range("IntVector::at_range_check");
	}
	else {
		return data[index];
	}
}

int & IntVector::at(unsigned index) {
	if (index >= sz) {
		throw out_of_range("IntVector::at_range_check");
	}
	else {
		return data[index];
	}
}

void IntVector::insert(unsigned index, int value) {
	if (index > sz) {
		throw out_of_range("IntVector::insert_range_check");
	}
	else {
		sz += 1;
		if (sz > cap) {
			expand();
		}
		for (unsigned int i = sz - 1; i > index; i--) {
			data[i] = data[i - 1];
		}
		data[index] = value;
	}
}

void IntVector::erase(unsigned index) {
	if (index >= sz) {
		throw out_of_range("IntVector::erase_range_check");
	}
	
	for (unsigned int i = index; i < sz; i++) {
		data[i] = data[i + 1];
	}
	
	sz -= 1;
}

const int & IntVector::front() const {
	return data[0];
}

int & IntVector::front() {
	return data[0];
}

const int & IntVector::back() const {
	return data[sz - 1];
}

int & IntVector::back() {
	return data[sz - 1];
}

void IntVector::assign(unsigned n, int value) {
	if (sz == 0 || cap == 0) {
		expand();
	}
	
	if (n > cap) {
		if (cap * 2 > n) {
			expand();
		}
		else {
			expand(n - cap);
		}
	}
	sz = n;
	
	for (unsigned int i = 0; i < sz; i++) {
		data[i] = value;
	}
}

void IntVector::push_back(int value) {
	sz += 1;
	
	if (sz > cap) {
		expand();
	}
	
	data[sz - 1] = value;
}

void IntVector::pop_back() {
	sz -= 1;
}

void IntVector::clear() {
	sz = 0;
}

void IntVector::resize(unsigned size, int value) {
	if (sz == 0) {
		expand();
		data[0] = value;
	}
	
	if (size <= cap && size > sz) {
		for (unsigned int i = sz; i < size; i++) {
			data[i] = value;
		}
	}
	else if (size > cap && size > sz) {
		if (cap * 2 > size) {
			expand();
		}
		else {
			expand(size - cap);
		}
		for (unsigned int i = sz; i < size; i++) {
			data[i] = value;
		}
	}
	sz = size;
}

void IntVector::reserve(unsigned n) {
	if (n > cap) {
		cap += n - cap;
	}
}