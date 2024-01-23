#include <iostream>
using namespace std;

struct Link {
	// Member variables
	Link* nextLink;
	string key;
	int value;
	// Initialize the struct via constructor
	Link(Link* next, string k, int val): nextLink(nullptr),
	key(k),
	value(val) {}
};

class HashMap {
	private:
	static const int size = 1000;
	Link* table[size] {
		nullptr
	};
	int hashFunc(string key, int length) {
		int hash = key.length() % length;
		return hash;
	}
	public:
	void insert(string key, int value) {
		int hashIndex = hashFunc(key, size);
		Link* newLink = new Link(nullptr, key, value);
		if (table[hashIndex] != nullptr) {
			Link* temp = table[hashIndex];
			if (!temp->nextLink) {
				temp->nextLink = newLink;
				return;
			}
			while(temp->nextLink) {
				if (temp->nextLink->nextLink == nullptr) {
					temp->nextLink->nextLink = newLink;
					return;
				}
				temp = temp->nextLink;
			}
			return;
		}
		table[hashIndex] = newLink;
		return;
	}
	void search(string key) {
		int index = hashFunc(key, 10);
		Link* tableValue = table[index];
		if (tableValue != nullptr) {
			if (tableValue->key == key) {
				cout << tableValue->value;
				return;
			}
			Link* temp = tableValue;
			while(temp->nextLink) {
				Link* next = temp->nextLink;
				if (next->key == key) {
					cout << next->value;
					return;
				}
				temp = temp->nextLink;
			}
			return;
		}
		cout << "No value at this index";
		return;
	}
	void remove(string key) {
		
	}
	void print() {
		string tab = " ";
		cout << "{" << endl;
		for (Link* link: table) {
			if (link != nullptr) {
				cout << tab << link->key << ": " << link->value << endl;
				if (link->nextLink != nullptr) {
					Link* temp = link;
					while(temp->nextLink) {
						Link* currentLink = temp->nextLink;
						cout << tab << currentLink->key << ": " << currentLink->value << endl;
						temp = currentLink;
					}
				}
			}
		}
		cout << "}" << endl;
	}
};


int main() {
	HashMap myNewMap;
	myNewMap.insert("Ryan", 28);
	myNewMap.insert("Bill", 34);
	myNewMap.insert("Joey", 60);
	myNewMap.insert("Billy", 37);
	myNewMap.insert("Joseph", 18);
	myNewMap.print();
	myNewMap.search("Joey");
	return 0;
}