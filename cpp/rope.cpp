#include <iostream>
using namespace std;
struct RopeNode {
	RopeNode* left;
	RopeNode* right;
	RopeNode* parent;
	string value;

	RopeNode(RopeNode* parent, RopeNode* left, RopeNode* right, string val) : parent(parent),
		left(left),
		right(right),
		value(val) {}
};


class Rope {
private:

	RopeNode* mainRoot = new RopeNode(nullptr, nullptr, nullptr, "New document");

	RopeNode* leafToAppendTo = findLeaf(mainRoot);

	void print(RopeNode* rope) {
		RopeNode* left = rope->left;
		RopeNode* right = rope->right;
		cout << rope->value;
		if (left) {
			print(left);
		}
		if (right) {
			print(right);
		}
	}

	RopeNode* findLeaf(RopeNode* node) {
		RopeNode* left = node->left;
		RopeNode* right = node->right;
		RopeNode* parent = node->parent;
		string value = node->value;
		if (value.length() > 50) {
			if (!left && !right) {
				node->left = new RopeNode(node, nullptr, nullptr, value);
				leafToAppendTo = node->left;
			}
			if (!left) {
				return findLeaf(right);
			}
			return findLeaf(left);
		}
		return node;
	}

public:

	void printDocument() {
		print(mainRoot);
	}

	void printSection(RopeNode* leaf) {
		if (!leaf) {
			cout << mainRoot->value;
			return;
		}
		cout << leaf->value;
	}

	void insert(string value) {
		leafToAppendTo = findLeaf(mainRoot);
		leafToAppendTo->value += value;
	}
};

int main() {
	Rope myRope;
	cout << "Before insert" << endl << "********" << endl;
	myRope.printDocument();
	myRope.insert(" This is a test string");
	myRope.insert(" I need to better understand how Ropes work to know how to program this data structure.");
	myRope.insert(" To be perfectly honest, I think I am a bit stuck here. It's because I need to read up on this and do some good lessons on rope data structures.");
	cout << endl << endl << "After insert" << endl << "********" << endl;
	myRope.printDocument();
	cout << endl;
	cout << "Printing only mainroot" << endl;
	myRope.printSection(nullptr);
	return 0;
}