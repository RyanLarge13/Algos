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
	int jump = 10;
	for (int i = 0;i < mySize; i += jump) {
		if (arr[i] == val) {
			return i;
		}
	}
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
		linearSearch(myArr, 1000);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Linear search runtime: " << duration.count() << endl;
	}
	{
		// Binary search calculation block
		auto start = chrono::high_resolution_clock::now();
		binarySearch(myArr, 1000);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Binary search runtime: " << duration.count() << endl;
	}
	return 0;
}