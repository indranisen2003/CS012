#include "minFunc.h"
const int * min(const int arr[], int arrSize) {
	if (arrSize == 1 || arrSize == 0) {
		return &arr[0];
	}
	else {
		const int * m = min(arr, arrSize - 1);
		if (arr[arrSize - 1] < *m) {
			return &arr[arrSize - 1];
		}
		else {
			return m;
		}
	}
}