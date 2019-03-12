#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "SortedSet.h"

int main() {
	//Initialize objects
	srand(time(nullptr));
	SortedSet sset = SortedSet();
	SortedSet sset2 = SortedSet();
	SortedSet sset3;
	int guaranteedNum = rand() % 100 + 1;
	int notGuaranteed = -5;
	
	//Add values
	for (int i = 0; i < 9; i++) {
		sset.push_back(rand() % 100 + 1);
	}
	sset.push_front(guaranteedNum);
	cout << "SortedSet 1: " << sset << endl;
	
	for (int i = 0; i < 9; i++) {
		sset2.push_back(rand() % 100 + 1);
	}
	sset2.add(guaranteedNum);
	cout << "SortedSet 2: " << sset2 << endl;
	
	sset3 = SortedSet(sset);
	cout << "SortedSet 3: " << sset3 << endl;
	
	cout << endl;
	
	//Check in function
	cout << "Is " << guaranteedNum << " inside Set 1?" << endl;
	cout << "Answer: " << sset.in(guaranteedNum) << endl;

	cout << "Is " << notGuaranteed << " inside Set 1?" << endl;
	cout << "Answer: " << sset.in(notGuaranteed) << endl;
	
	cout << "Is " << guaranteedNum << " inside Set 2?" << endl;
	cout << "Answer: " << sset2.in(guaranteedNum) << endl;

	cout << "Is " << notGuaranteed << " inside Set 2?" << endl;
	cout << "Answer: " << sset2.in(notGuaranteed) << endl;
	
	cout << "Is " << guaranteedNum << " inside Set 3?" << endl;
	cout << "Answer: " << sset3.in(guaranteedNum) << endl;

	cout << "Is " << notGuaranteed << " inside Set 3?" << endl;
	cout << "Answer: " << sset3.in(notGuaranteed) << endl;
	
	cout << endl;
	
	//Testing | operator
	cout << "Testing | operator..." << endl;
	cout << "sset | sset2: " << (sset | sset2) << endl;
	
	cout << endl;
	
	//Testing & operator
	cout << "Testing & operator..." << endl;
	cout << "sset3 & sset2: " << (sset3 & sset2) << endl;
	
	return 0;
}
