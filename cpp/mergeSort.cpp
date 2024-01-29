#include <iostream>
#include <vector>
using namespace std;

void merge(vector < int > arr, size_t left, size_t mid, size_t right) {
	size_t n1 = mid - left + 1;
	size_t n2;
};

void mergeSort(vector < int >& arr, size_t left, size_t right) {
	if (left < right) {
		size_t mid = left + (right - left) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	vector < int > myNums{
		3,
		5,
		2,
		7,
		5,
		9,
		7,
		1,
		2,
		6
	};
	cout << endl << "Before merge sort" << endl;
	for (int i : myNums) {
		cout << i << ", ";
	}
	cout << endl;
	mergeSort(myNums, 0, myNums.size() - 1);
	cout << endl << "After merge sort" << endl;
	for (int i : myNums) {
		cout << i << ", ";
	}
	cout << endl;
	return 0;
}