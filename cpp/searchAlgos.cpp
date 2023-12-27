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
	int jump = 100;
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

//int exponentialSearch(int arr[], int val) {}

//int ternarySearch(int arr[], int val) {}

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
		linearSearch(myArr, 500);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Linear search runtime: " << duration.count() << endl;
	}
	{
		// Binary search calculation block
		auto start = chrono::high_resolution_clock::now();
		binarySearch(myArr, 500);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Binary search runtime: " << duration.count() << endl;
	}
	{
		// Jump search calculation block
		auto start = chrono::high_resolution_clock::now();
		jumpSearch(myArr, 500);
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast < chrono::microseconds > (end - start);
		cout << "Jump search runtime: " << duration.count() << endl;
	}
	return 0;
}