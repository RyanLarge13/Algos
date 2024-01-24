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
		DblLink* link = head;
		while (link->nextLink != head) {
			cout << link->value;
			link = link->nextLink;
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
			return;
		}
		DblLink* newLink = new DblLink(head, head->nextLink, value);
		head->nextLink = newLink;
		return;
	}
	void remove() {}
	// void shift() {}
};

int main() {
	DoubleyLinkedList dblList;
	dblList.print();
	dblList.findValue(0);
	dblList.findValue(1);
	dblList.insert(10);
	dblList.insert(8);
	dblList.findValue(10);
	dblList.print();
	return 0;
}