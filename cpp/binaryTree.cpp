#include <iostream>
using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int value;

    Node(Node* parent, Node* left, Node* right, int value) : parent(parent), left(left), right(right), value(value) {}
};

class BinaryTree {
private:

    Node* mainRoot = nullptr;

    void print(Node* node) {
        Node* left = node->left;
        Node* right = node->right;
        cout << node->value << endl;
        if (left != nullptr) {
            print(left);
        }
        if (right != nullptr) {
            print(right);
        }
    }

    void insert(Node* node, int value) {
        Node* left = node->left;
        Node* right = node->right;
        Node* newNode = new Node(node, nullptr, nullptr, value);
        if (value == node->value) {
            return;
        }
        if (!left && !right) {
            if (value < node->value) {
                node->left = newNode;
                return;
            }
            node->right = newNode;
            return;
        }
        if (value < node->value) {
            if (node->left) {
                delete newNode;
                insert(node->left, value);
            }
            node->left = newNode;
            return;
        }
        if (value > node->value) {
            if (node->right) {
                delete newNode;
                insert(node->right, value);
            }
            node->right = newNode;
            return;
        }
    }

public:

    void printValues() {
        if (!mainRoot) {
            cout << "Your tree is empty, insert some values" << endl;
        }
        print(mainRoot);
    }

    void insertValue(int value) {
        if (!mainRoot) {
            mainRoot = new Node(nullptr, nullptr, nullptr, value);
            return;
        }
        insert(mainRoot, value);
    }
};

int main() {
    BinaryTree myTree;
    myTree.insertValue(50);
    myTree.insertValue(20);
    // myTree.insertValue(10);
    myTree.printValues();
    return 0;
}