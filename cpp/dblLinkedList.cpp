#include <iostream>
using namespace std;

struct DblLink {
	DblLink* prevLink;
	DblLink* nextLink;
	int value;
	DblLink(DblLink* prev, DblLink* next, int val): prevLink(prev),
	nextLink(next),
	value(val) {}
};

class DoubleyLinkedList {
	private:
	DblLink* head = new DblLink(nullptr, nullptr, 0);
	public:
	void print() {
		if (!head) {
			cout << "Your list is empty" << endl;
			return;
		}
		if (!head->nextLink) {
			cout << head->value << endl;
			return;
		}
		DblLink* link = head->nextLink;
		while (link != head) {
			DblLink* prevPtr = link->prevLink;
			DblLink* nextPtr = link->nextLink;
			cout << "prev: " << prevPtr->value << endl << "current: " << link->value << endl << "next: " << nextPtr->value << endl << endl;
			link = link->nextLink;
		}
		return;
	}
	void printReverse() {
		if (!head) {
			cout << "Your list is empty" << endl;
			return;
		}
		if (!head->prevLink) {
			cout << head->value << endl;
			cout << "No prev link" << endl;
			return;
		}
		DblLink* link = head->prevLink;
		while (link != head) {
			cout << link->value << endl;
			link = link->prevLink;
		}
		return;
	}
	void findValue(int value) {
		if (!head) {
			cout << "Your list is empty" << endl;
			return;
		}
		if (head->value == value) {
			cout << "!1!" << endl;
			return;
		}
		if (head->nextLink) {
			DblLink* temp = head->nextLink;
			while (temp != head) {
				if (temp == nullptr) {
					cout << "!0!" << endl;
					return;
				}
				if (temp->value == value) {
					cout << "!1!" << endl;
					return;
				}
				temp = temp->nextLink;
			}
			return;
		}
		cout << "!0!" << endl;
	}
	void insert(int value) {
		if (!head) {
			DblLink* newLink = new DblLink(nullptr, nullptr, value);
			head = newLink;
			return;
		}
		if (!head->nextLink) {
			DblLink* newLink = new DblLink(head, head, value);
			head->nextLink = newLink;
			head->prevLink = newLink;
			return;
		}
		DblLink* temp = head->nextLink;
		DblLink* newLink = new DblLink(head, head->nextLink, value);
		head->nextLink = newLink;
		temp->prevLink = newLink;
		return;
	}
	void removeValue(int value) {
		if (!head) {
			cout << "Your list is empty" << endl;
			return;
		}
		if (!head->nextLink) {
			cout << "No value in this list matching your number is available to delete" << endl;
			return;
		}
		DblLink* temp = head->nextLink;
		while (temp != head) {
			if (temp->value == value) {
				DblLink* next = temp->nextLink;
				DblLink* prev = temp->prevLink;
				next->prevLink = prev;
				prev->nextLink = next;
				cout << "Removing value: " << temp->value << endl;
				delete temp;
				return;
			}
			temp = temp->nextLink;
		}
		cout << "No value in this list matching your number is available to delete" << endl;
		return;
	}
};

int main() {
	DoubleyLinkedList dblList;
	dblList.insert(10);
	dblList.insert(8);
	dblList.insert(9);
	dblList.insert(5);
	dblList.insert(1);
	dblList.insert(3);
	dblList.insert(7);
	dblList.print();
	cout << endl << endl;
	dblList.printReverse();
	dblList.removeValue(8);
	dblList.printReverse();
	return 0;
}