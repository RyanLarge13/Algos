#include <iostream>
using namespace std;

void insertionSort(int arr[]) {
	for (int i = 0; i < arr.length(); i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && key < arr[j]) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main() {
	int myArr[10] {
		1,
		5,
		2,
		8,
		1,
		0,
		2,
		8,
		6,
		5
	};
	insertionSort(myArr);
	cout << endl;
	for (int i = 0; i < 10; i++) {
		cout << myArr[i] << ", ";
	}
	cout << endl;
	return 0;
}