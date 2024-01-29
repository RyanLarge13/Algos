#include <iostream>
#include <vector>
using namespace std;

void merge(vector < int > arr, size_t left, size_t mid, size_t right) {
	size_t n1 = mid - left + 1;
	size_t n2 = right - mid;
	vector <int> subLeft(arr.begin() + left, arr.begin() + left + n1);
	vector <int> subRight(arr.begin() + mid + 1, arr.begin() + mid + 1+ n2);
	size_t i = 0, j = 0; k = left;
	while (i < n1 && j < n2) {
		if (leftSub[i] <= rightSub[j]) {
			arr[k] = leftSub[i];
			++i;
		} else {
			arr[k] = rightSub[j];
			j++;
		}
		++k;
	}
	while (i < n1) {
		arr[k] =leftSub[i];
		++i;
		++k;
	}
	while (j < n2) {
		arr[k] = rightSub[j];
		++j;
		++k;
	}
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