#include <iostream>
using namespace std;

void bubbleIt(int jumbledMess[]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8 - 1; j++) {
			if (jumbledMess[j] > jumbledMess[j + 1]) {
				int temp = jumbledMess[j];
				jumbledMess[j] = jumbledMess[j + 1];
				jumbledMess[j + 1] = temp;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < 8; i++) {
		cout << jumbledMess[i] << ", ";
	}
	cout << endl;
}

int main() {
	int myArr[8] {
		2,
		7,
		1,
		0,
		5,
		3,
		8,
		3
	};
	bubbleIt(myArr);
	return 0;
}