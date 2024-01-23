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

class hashMap {
	private:
	static const int size = 10;
	Link* table[size];
	int hashFunc(string key, int length) {
		int len = key.length();
		return len % length;
	}
	public:
	void insert() {} 
	void search() {} 
	void remove() {} 
	void print() {} 
};


int main() {
	return 0;
}