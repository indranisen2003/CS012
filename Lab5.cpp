/*
UCR CS012
Lab 5
Created by Kashyap Panda
*/

#include <iostream>
using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize);

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int &arraySize, int index);


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize);


const int ARR_CAP = 10;

int main() {
    // 1. Declare an array of doubles of size 10.
    double doubles[10];
    int arraySize = ARR_CAP;
    
    // 2. Fill the array with 10 doubles entered by the user.
    cout << "Enter 10 values:" << endl;
    double num;
    for (int i = 0; i < arraySize; i++) {
        cin >> num;
        doubles[i] = num;
    }
    cout << endl;
    
    // 3. Call the mean function passing it this array and output the 
    // value returned.
    cout << "Mean: " << mean(doubles, arraySize);
    cout << endl << endl;
    
    // 4. Ask the user for the index (0 to 9) of the value they want to remove.
    int index;
    cout << "Enter index of value to be removed: ";
    cin >> index;
    cout << endl;
	
    // 5. Call the display function to output the array.
    cout << "Before removing value: ";
    display(doubles, arraySize);
    cout << endl;

    // 6. Call the remove function to remove the value at the index
    // provided by the user.
    remove(doubles, arraySize, index);

    // 7. Call the display function again to output the array
    // with the value removed.
    cout << "After removing value: ";
    display(doubles, arraySize);
    cout << endl;

	return 0;
}

double mean(const double array[], int arraySize) {
    double mean = 0;
    for (int i = 0; i < arraySize; i++) {
        mean += array[i];
    }
    return mean / arraySize;
}

void remove(double array[], int &arraySize, int index) {
    if (index != arraySize - 1) {
        for (int i = index; i < arraySize; i++) {
            array[i] = array[i + 1];
        }
    }
    arraySize -= 1;
}

void display(const double array[], int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (i != arraySize - 1) {
            cout << array[i] << ", ";
        }
        else {
            cout << array[i];
        }
    }
}
