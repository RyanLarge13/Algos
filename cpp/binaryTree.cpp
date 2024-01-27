#include <iostream>
using namespace std;

struct Node {
	Node* left;
	Node* right;
	Node* parent;
	string str;
	Node(Node* left, Node* right, Node* parent, string str): left(left),
	right(right),
	parent(parent),
	str(str) {}
};

class Rope {
	private:
	Node* root = new Node(nullptr, nullptr, nullptr, "New document rope");
	void print(Node* node) {
		if (!node) return;
		print(node->left);
		cout << node->str;
		print(node->right);
	}
	public:
	void printRope() {
		print(root);
		cout << endl;
	}
	void insertRope(const string& value, int position) {}
};

int main() {
	Rope newDocument;
	newDocument.printRope();
	return 0;
}