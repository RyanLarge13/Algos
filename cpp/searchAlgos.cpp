#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;

const int mySize = 1000000;
int myArr[mySize];

int init() {
	for (int i = 0; i < mySize; i++) {
		myArr[i] = i;
	}
	return 0;
}

int complexOp() {
	int res;
	for (int i = 0; i < mySize; i++) {
		res = i + i;
	}
	return 0;
}

int binarySearch(int arr[], int val) {
	int low = 0;
	int high = mySize;
	while (low < high) {
		int mid = low + (high - low) / 2;
		if (arr[mid] == val) {
			return mid;
		} else if (arr[mid] < val) {
			low = mid + 1;
		} else if (arr[mid] > val) {
			high = mid;
		}
		complexOp();
	}
	return -1;
}

int jumpSearch(int arr[], int val) {
	int low = 0;
	int high = mySize;
	int jump = 50000;
	while (low < high) {
		int next = low + jump;
		if (next >= mySize) {
			next = mySize - 1;
		}
		if (arr[next] == val) {
			return next;
		}
		if (arr[next] < val) {
			low = next + 1;
		}
		if (arr[next] > val) {
			jump -= 1;
			if (jump < 1) {
				jump = 1;
			}
		}
		complexOp();
	}
	return -1;
}


int ternarySearch(int arr[], int val) {
	int low = 0;
	int high = mySize;
	while (low < high) {
		int firstMax = low + (high - low) / 3;
		int secondMax = low + 2 * (high - low) / 3;
		if (val == arr[low] || val == arr[high]) {
			return val;
		}
		if (arr[firstMax] == val) {
			return firstMax;
		}
		if (arr[secondMax] == val) {
			return secondMax;
		}
		if (val < firstMax) {
			high = firstMax;
		}
		if (val > firstMax && val < secondMax) {
			high = secondMax;
			low = firstMax + 1;
		}
		if (val > secondMax && val < high) {
			low = secondMax + 1;
		}
		complexOp();
	}
	return -1;
}

int quadraticSearch(int arr[], int val) {
	int low = 0;
	int high = mySize;
	while (low < high) {
		int firstMax = low + (high - low) / 4;
		int secondMax = low + 2 * (high - low) / 3;
		int thirdMax = low + 3 * (high - low) / 3;
		if (val == arr[low] || val == arr[high]) {
			return val;
		}
		if (arr[firstMax] == val) {
			return firstMax;
		}
		if (arr[secondMax] == val) {
			return secondMax;
		}
		if (arr[thirdMax] == val) {
			return secondMax;
		}
		if (val < firstMax) {
			high = firstMax;
		}
		if (val > firstMax && val < secondMax) {
			high = secondMax;
			low = firstMax + 1;
		}
		if (val > secondMax && val < thirdMax) {
			low = secondMax + 1;
		}
		if (val > secondMax && val < high) {
			low = thirdMax + 1;
		}
		complexOp();
	}
	return -1;
}

int exponentialSearch(int arr[], int val) {
	if (arr[0] == val) {
		return 0;
	}
	int range = 1;
	while (range < mySize && arr[range] <= val) {
		range *= 2;
	}
	int start = range / 2;
	int end = min(range, mySize - 1);

	return 0; // binarySearch(); can't be called with the new array length, implement your own custom exponentialSearch binarySearch function
}

int linearSearch(int arr[], int val) {
	for (int i = 0; i < mySize; i++) {
		if (arr[i] == val) {
			return i;
		}
		complexOp();
	}
	return -1;
}

int main() {
	init();
	{
		// Linear search calculation block
		auto start = chrono::high_resolution_clock::now();
		linearSearch(myArr, 100);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Linear search runtime:      " << duration.count() << endl;
	}
	{
		// Exponential search calculation block
		auto start = chrono::high_resolution_clock::now();
		exponentialSearch(myArr, 20);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Exponential search runtime: " << duration.count() << endl;
	}
	{
		// Binary search calculation block
		auto start = chrono::high_resolution_clock::now();
		binarySearch(myArr, 250001);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Binary search runtime:      " << duration.count() << endl;
	}
	{
		// Jump search calculation block
		auto start = chrono::high_resolution_clock::now();
		jumpSearch(myArr, 250001);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Jump search runtime:        " << duration.count() << endl;
	}
	{
		// Ternary search calculation block
		auto start = chrono::high_resolution_clock::now();
		ternarySearch(myArr, 250001);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Ternary search runtime:     " << duration.count() << endl;
	}
	{
		// Quadratic search calculation block
		auto start = chrono::high_resolution_clock::now();
		quadraticSearch(myArr, 250001);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Quadratic search runtime:   " << duration.count() << endl;
	}
	return 0;
}